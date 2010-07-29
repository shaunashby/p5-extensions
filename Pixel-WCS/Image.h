//____________________________________________________________________ 
// File: Image.h
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-26 15:48:16+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef IMAGE_H             
#define IMAGE_H             

#include <string>

// New class declaration:
class Image {
public:
  Image(std::string & path);
  Image(const Image & i);

  virtual ~Image();
  
  // Public methods:
  char * ctype1();
  char * ctype2();

  double crval1();
  double crval2();

  double crpix1();
  double crpix2();

  double * cd();

  double lambda();
  
  long equinox();

  char * refframe();

  int size_x();
  int size_y();

  struct WorldCoor* wcs() const;

private:
  // Function to read the FITS image file to
  // obtain values to initialize the object:
  void _init(std::string & path);

private:
  struct WorldCoor *m_wcs;

  int m_sizex;
  int m_sizey;
  
  char     m_refframe[20];
  char     m_ctype1[20];
  char     m_ctype2[20];

  double   m_crpix1;
  double   m_crval1;
  
  double   m_crpix2;
  double   m_crval2;

  double   m_cd[4];

  long     m_equinox;

  double   m_lambda;
  
};

#endif // IMAGE_H             
