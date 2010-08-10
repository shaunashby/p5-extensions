/***********************************************************************/
/*                                                                     */
/*                            I S D C                                  */
/*                                                                     */
/*                           SKY PIXEL                                 */
/*                                                                     */
/*                           genpixels                                 */
/*                                                                     */
/*                                                                     */
/*  File:      pix_to_pix.h                                            */
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
#ifndef PIX_TO_PIX_INCLUDED
#define PIX_TO_PIX_INCLUDED

extern "C" {    
  void fk52gal (double *dtheta, double *dphi);
  void gal2fk5 (double *dtheta, double *dphi);
};

#include <deque>

///////////////////////////////////////////////////////////////////////////////
///  container to store on pair of coordinates                                 
class PixelCoord
{
public:
   PixelCoord(double xCoord, double yCoord, bool valid)
      : m_xCoord(xCoord), m_yCoord(yCoord), m_valid(valid) {}

   double GetX()     {return m_xCoord;}
   double GetY()     {return m_yCoord;}
   bool   GetValid() {return m_valid;}

private:
   double m_xCoord;
   double m_yCoord;
   bool   m_valid;
};


///////////////////////////////////////////////////////////////////////////////
/// one dimension of a vector (deque), which stores also the index of the      
/// first entry.                                                               
template <class T>
class PixelLine : public std::deque<T>
{
public:
   int FirstIndex()                       {return m_firstIndex;};
   void SetFirstIndex(int firstIndex)     {m_firstIndex = firstIndex;}

   T & operator [] (double index)         {return std::deque<T>::operator[]( (int)index - m_firstIndex );}
   void push_front(const T &val)          {std::deque<T>::push_front(val); m_firstIndex--;}

private:
   int m_firstIndex;
};



///////////////////////////////////////////////////////////////////////////////
/// class to convert input pixels coordinates to output pixel coordinates and  
/// vice versa.                                                                
class PixToPix
{
public:
   PixToPix(struct WorldCoor * outWcs, double lowL, double highL, 
            double lowB, double highB);

   ~PixToPix() {};

   void SetInWcs( struct WorldCoor * inWcs);

   bool InToOut(double xIn, double yIn, double & xOut, double & yOut);
   void OutToIn(double xOut, double yOut, double & xIn, double & yIn);

private:
    PixelCoord CalcOutPixels(double xIn, double yIn);
    PixelCoord CalcInPixels(double xOut, double yOut);

    struct WorldCoor * m_outWcs;
    struct WorldCoor * m_inWcs;

    /// limits of output area
    double m_lowL;           
    double m_highL;
    double m_lowB;
    double m_highB;
   

   // output coordinates of input pixel [x][y]
   PixelLine< PixelLine < PixelCoord> >   m_out;
   // input coordinates of output pixel [x][y]
   PixelLine< PixelLine < PixelCoord> >   m_in;

};

#endif //PIX_TO_PIX_INCLUDED

