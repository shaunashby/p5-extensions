//____________________________________________________________________ 
// File: ImageParams.h
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-29 17:02:08+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef IMAGEPARAMS_H       
#define IMAGEPARAMS_H       

#include <iosfwd>

// ImageParams class: Parameters for creating image products
class ImageParams {
public:
  ImageParams(double ra, double dec, double size_x, double size_y);
  virtual ~ImageParams();
  
  // Public methods:
  const double ra() const;
  const double dec() const;
  const double size_x() const;
  const double size_y() const;

  // Pixel sizes:
  void   scaleA(double pxsize_x);
  void   scaleB(double pxsize_y);

  const double scaleA() const;
  const double scaleB() const;

  void         coordrefframe(char * ref);
  const char * coordrefframe() const;
  
  void coordequinox(long eq);
  const long coordequinox() const;
  
  void         coordprojection(char * proj);
  const char * coordprojection() const;

  void   coordrefpixelA(double crpix1);
  const double coordrefpixelA() const;

  void   coordrefpixelB(double crpix2);
  const double coordrefpixelB() const;
  
  void   coordrefvalueA(double crval1);
  const double coordrefvalueA() const;
  
  void   coordrefvalueB(double crval2);
  const double coordrefvalueB() const;

  void cd(double *cd);
  const double * cd() const;

private:
  const double m_ra;
  const double m_dec;
  const double m_size_x;
  const double m_size_y;

  double  m_scale_a;
  double  m_scale_b;

  char * m_refframe;
  char * m_coord_proj;

  long  m_equinox;
  
  double m_coordrefpix_a;
  double m_coordrefpix_b;

  double m_coordrefval_a;
  double m_coordrefval_b;

  double * m_cd;
  
};

// Operators:
std::ostream & operator<< (std::ostream & O, const ImageParams & i);

#endif // IMAGEPARAMS_H
