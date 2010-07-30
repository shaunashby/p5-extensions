//____________________________________________________________________ 
// File: Image.cpp
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-26 16:38:13+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include "Image.h"
#include "dal.h"

#include <iostream>

extern "C" {
  void wcsfree(struct WorldCoor *wcs);

  struct WorldCoor* wcskinit(int naxis1, int naxis2, char *ctype1, char *ctype2,
			     double crpix1, double crpix2,
			     double crval1, double crval2,
			     double *cd,
			     double cdelt1, double cdelt2, double crota, int equinox, double epoch);
}

Image::Image(std::string & path) /* Default image sizes */
  : m_wcs(0), m_sizex(20), m_sizey(20) {
  _init(path);
}

Image::Image(const Image & image)
{}

Image::~Image(){
  if (m_wcs != 0)
    ::wcsfree(m_wcs);
}

const char * Image::ctype1() const {
  // Remove first 5 characters:
  return m_ctype1+5;
}

const char * Image::ctype2() const {
  // Remove first 5 characters:
  return m_ctype2+5;
}

const double Image::crpix1() const {
  return m_crpix1;
}

const double Image::crpix2() const {
  return m_crpix2;
}

const double Image::crval1() const {
  return m_crval1;
}

const double Image::crval2() const {
  return m_crval2;
}

const double * Image::cd() const {
  return m_cd;
}

const double Image::lambda() const {
  return m_lambda;
}

const long Image::equinox() const {
  return m_equinox;
}

const char * Image::refframe() const {
  return m_refframe;
}

const int Image::size_x() const {
  return m_sizex;
}

const int Image::size_y() const {
  return m_sizey;
}

struct WorldCoor* Image::wcs() const {
  return m_wcs;
}

void Image::_init(std::string & path) {
  // FIXME: Use exceptions
  dal_element *image;
  int m_status = 0;

  m_status = DALobjectOpen(path.c_str(), &image, m_status);
  
  if (m_status != 0) {
    // FIXME:
    std::cerr << "[Image]: Unable to open " << path << std::endl;
    DALobjectClose(image, DAL_SAVE, 0);
    m_status = -36270;
    return;
  }
  
  // Populate the data members from the data within the FITS image file:
  m_status = DALattributeGet(image, "CTYPE1", DAL_CHAR, m_ctype1, NULL, NULL, m_status);
  m_status = DALattributeGet(image, "CTYPE2", DAL_CHAR, m_ctype2, NULL, NULL, m_status);
  m_status = DALattributeGet(image, "CRVAL1", DAL_DOUBLE, &m_crval1, NULL, NULL, m_status);
  m_status = DALattributeGet(image, "CRVAL2", DAL_DOUBLE, &m_crval2, NULL, NULL, m_status);
  m_status = DALattributeGet(image, "CD1_1", DAL_DOUBLE, &m_cd[0], NULL, NULL, m_status);
  m_status = DALattributeGet(image, "CD1_2", DAL_DOUBLE, &m_cd[1], NULL, NULL, m_status);
  m_status = DALattributeGet(image, "CD2_1", DAL_DOUBLE, &m_cd[2], NULL, NULL, m_status);
  m_status = DALattributeGet(image, "CD2_2", DAL_DOUBLE, &m_cd[3], NULL, NULL, m_status);
  m_status = DALattributeGet(image, "RADECSYS", DAL_CHAR, m_refframe, NULL, NULL, m_status);
  m_status = DALattributeGet(image, "EQUINOX", DAL_LONG, &m_equinox, NULL, NULL, m_status);
  m_status = DALattributeGet(image, "SIZE1", DAL_LONG, &m_sizex, NULL, NULL, m_status);
  m_status = DALattributeGet(image, "SIZE2", DAL_LONG, &m_sizey, NULL, NULL, m_status);  
  
  if (m_status != 0) {
    // FIXME:
    std::cerr << "ERROR: Failure while reading attribute from FITS image file." << std::endl;
    return;
  }
  
  m_crpix1 = m_sizex/2.0 + 0.5;
  m_crpix2 = m_sizey/2.0 + 0.5;
  
  // Now populate the WorldCor struct:
  m_wcs = ::wcskinit(m_sizex, m_sizey,
		     m_ctype1, m_ctype2,
		     m_crpix1, m_crpix2,
		     m_crval1, m_crval2,
		     m_cd, 0.0, 0.0, 0.0, m_equinox, 0.0);
  
  // Close the table:
  DALobjectClose(image, DAL_SAVE, 0);
}
