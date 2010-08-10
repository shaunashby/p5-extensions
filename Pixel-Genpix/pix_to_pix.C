/***********************************************************************/
/*                                                                     */
/*                            I S D C                                  */
/*                                                                     */
/*                           SKY PIXEL                                 */
/*                                                                     */
/*                           genpixels                                 */
/*                                                                     */
/*                                                                     */
/*  File:      pix_to_pix.C                                            */
/*  Version:   1.0                                                     */
/*  Component: genpixels   													     */
/*                                                                     */
/*  Authors:   Reiner Rohlfs (RR)                                      */
/*             ISDC                                                    */
/*                                                                     */
/*  Purpose:   class to convert input pixel coordinate to output       */
/*             pixel coordinates and vice versa                        */
/*                                                                     */
/*  Revision History:                                                  */
/*                                                                     */
/*  version 1.0: 24/02/10 RR  First version                            */
/*                                                                     */
/***********************************************************************/

//#include <genpixels.h>
#include "pix_to_pix.h"
#include "wcs.h"

///////////////////////////////////////////////////////////////////////////////
PixToPix::PixToPix(struct WorldCoor * outWcs, double lowL, double highL, 
                   double lowB, double highB)
{
   m_outWcs       = outWcs;
   m_inWcs        = NULL;

   m_lowL         = lowL;
   if (m_lowL < 0) m_lowL += 360;
   m_highL        = highL;
   m_lowB         = lowB;
   m_highB        = highB;
}

///////////////////////////////////////////////////////////////////////////////
// all data are deleted, if inWcs is different to the previous WorldCoor       
// structure                                                                   
void PixToPix::SetInWcs( struct WorldCoor * inWcs)
{
   if (m_inWcs == NULL)
      {
      m_inWcs = inWcs;
      return;
      }

   // is it the same inWcs as the previous one?
   if (inWcs->xref      != m_inWcs->xref    ||
       inWcs->yref      != m_inWcs->yref    ||
       inWcs->xrefpix   != m_inWcs->xrefpix ||
       inWcs->yrefpix   != m_inWcs->yrefpix ||
       inWcs->cd[0]     != m_inWcs->cd[0]   ||
       inWcs->cd[1]     != m_inWcs->cd[1]   ||
       inWcs->cd[2]     != m_inWcs->cd[2]   ||
       inWcs->cd[3]     != m_inWcs->cd[3]       )
      {
      m_inWcs = inWcs;
      m_out.clear();
      m_in.clear();
      }

}

///////////////////////////////////////////////////////////////////////////////
// calculates and returns the output pixel coordinates of the input            
// coordinates xIn / yIn                                                       
// PixelCoord.m_valid is set to false if the coordinates outside of the        
// of the output area                                                          
PixelCoord PixToPix::CalcOutPixels(double xIn, double yIn)
{
   double xPos, yPos;  // sky coordinates
   double xOut, yOut;  

   bool valid = true;
   int offscl = 0;

   /* Pixels in fits images don't start at 0, but 1.  C images start at 0...*/

   pix2wcs(m_inWcs, xIn, yIn, &xPos, &yPos);

   /* Now, xPos and yPos are in equatorial (ie, RA, DEC).
      This is because this is what our input is in, ie, if you have something not
      integral this won't work */

   /* Convert to Glactic */
   fk52gal(&xPos,&yPos); 

   // test if we are inside the current sky area
   if (yPos < m_lowB || yPos > m_highB)
      valid = false;

   if (m_lowL < m_highL)
      {
      // normal case
      if (xPos < m_lowL || xPos > m_highL)
         valid = false;
      }
   else
      {
      // we crossed the 0/360 line
      if (xPos < m_lowL && xPos > m_highL)
         valid = false;
      }


   if (valid)
      { 
      wcs2pix(m_outWcs, xPos, yPos, &xOut, &yOut, &offscl);
      if (offscl) valid = false;
      }

   return PixelCoord(xOut, yOut, valid);
}

///////////////////////////////////////////////////////////////////////////////
// calculates and returns the input pixel coordinates of the outut             
// coordinates xOut / yOut                                                     
PixelCoord PixToPix::CalcInPixels(double xOut, double yOut)
{

  double xPos, yPos;   // sky coordinates
  double xIn, yIn;
  
  int offscl = 0;

  pix2wcs(m_outWcs, xOut, yOut, &xPos, &yPos);

  gal2fk5(&xPos, &yPos); 

  wcs2pix(m_inWcs, xPos, yPos, &xIn, &yIn, &offscl);

  return PixelCoord(xIn, yIn, true);
}

///////////////////////////////////////////////////////////////////////////////
// returns the output pixel coordinates xOut / yOut of the input coordinates   
// xIn / yIn. They are calculates if not already known.                        
// xIn / YIn must always define a corner of a pixel, i.e. they are always      
// an integer number + 0.5 !!!                                                 
//                                                                             
// returns false if the output pixel would be outside of the area, defined     
// by the parameters of the constructor of this PixToPix class                 
bool PixToPix::InToOut(double xIn, double yIn, double & xOut, double & yOut)
{
   // make sure that the first index exist in m_out
   if (m_out.size() == 0)
      {
      m_out.SetFirstIndex( (int) xIn);
      PixelLine <PixelCoord> line;
      m_out.push_back(line);
      }

   while ((int)xIn < m_out.FirstIndex() )
      {
      PixelLine <PixelCoord> line;
      m_out.push_front(line);
      }

   while ((int)xIn >= m_out.FirstIndex() + m_out.size())
      {
      PixelLine <PixelCoord> line;
      m_out.push_back(line);
      }

   // make sure that the second index exist in m_out[xIn]

   PixelLine < PixelCoord> & row = m_out[xIn];
   if (row.size() == 0)
      {
      row.SetFirstIndex( (int) yIn);
      row.push_back(CalcOutPixels(xIn, yIn));
      }

   while ((int)yIn < row.FirstIndex() )
      {
      row.push_front(CalcOutPixels(xIn, row.FirstIndex() - 0.5) );
      }

   while ((int)yIn >= row.FirstIndex() + row.size())
      {
      row.push_back(CalcOutPixels(xIn, row.FirstIndex() + row.size() + 0.5) );
      }

   PixelCoord & result = row[yIn];
   xOut = result.GetX();
   yOut = result.GetY();

   return result.GetValid();
}

///////////////////////////////////////////////////////////////////////////////
// returns the input pixel coordinates xIn / yIn of the output coordinates     
// xOut / yOut. They are calculates if not already known.                      
// xOut / YOut must always define a corner of a pixel, i.e. they are always    
// an integer number + 0.5 !!!                                                 
void PixToPix::OutToIn(double xOut, double yOut, double & xIn, double & yIn)
{
   // make sure that the first index exist in m_out
   if (m_in.size() == 0)
      {
      m_in.SetFirstIndex( (int) xOut);
      PixelLine <PixelCoord> line;
      m_in.push_back(line);
      }

   while ((int)xOut < m_in.FirstIndex() )
      {
      PixelLine <PixelCoord> line;
      m_in.push_front(line);
      }

   while ((int)xOut >= m_in.FirstIndex() + m_in.size())
      {
      PixelLine <PixelCoord> line;
      m_in.push_back(line);
      }

   // make sure that the second index exist in m_in[xOut]

   PixelLine < PixelCoord> & row = m_in[xOut];
   if (row.size() == 0)
      {
      row.SetFirstIndex( (int) yOut);
      row.push_back(CalcInPixels(xOut, yOut));
      }

   while ((int)yOut < row.FirstIndex() )
      {
      row.push_front(CalcInPixels(xOut, row.FirstIndex() - 0.5) );
      }

   while ((int)yOut >= row.FirstIndex() + row.size())
      {
      row.push_back(CalcInPixels(xOut, row.FirstIndex() + row.size() + 0.5) );
      }
   PixelCoord & result = row[yOut];
   xIn = result.GetX();
   yIn = result.GetY();

}
