//____________________________________________________________________ 
// File: ImageParams.cpp
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-29 17:47:03+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------

#include "ImageParams.h"
#include <ostream>

ImageParams::ImageParams(double ra, double dec, double size_x, double size_y)
  : m_ra(ra), m_dec(dec), m_size_x(size_x), m_size_y(size_y), m_cd(new std::vector<double>[4])
{}

ImageParams::~ImageParams()
{}

const double ImageParams::ra() const {
  return m_ra;
}

const double ImageParams::dec() const {
  return m_dec;
}

const double ImageParams::size_x() const {
  return m_size_x;
}

const double ImageParams::size_y() const {
  return m_size_y;
}

void ImageParams::scaleA(double pxsize_x) {
  m_scale_a = pxsize_x;
}

const double ImageParams::scaleA() const {
  return m_scale_a;
}

void ImageParams::scaleB(double pxsize_y) {
  m_scale_b = pxsize_y;
}

const double ImageParams::scaleB() const {
  return m_scale_b;
}

void ImageParams::coordrefframe(const char * ref) {
  m_refframe = ref;
}

const char * ImageParams::coordrefframe() const {
  return m_refframe;
}

void ImageParams::coordequinox(long eq) {
  m_equinox = eq;
}

const long ImageParams::coordequinox() const {
  return m_equinox;
}
  
void ImageParams::coordprojection(const char * proj) {
  m_coord_proj = proj;
}

const char * ImageParams::coordprojection() const {
  return m_coord_proj;
}

void ImageParams::coordrefpixelA(double crpix1) {
  m_coordrefpix_a = crpix1;
}

const double ImageParams::coordrefpixelA() const {
  return m_coordrefpix_a;
}

void ImageParams::coordrefpixelB(double crpix2) {
  m_coordrefpix_b = crpix2;
}

const double ImageParams::coordrefpixelB() const {
  return m_coordrefpix_b;
}

void ImageParams::coordrefvalueA(double crval1) {
  m_coordrefval_a = crval1;
}

const double ImageParams::coordrefvalueA() const {
  return m_coordrefval_a;
}

void ImageParams::coordrefvalueB(double crval2) {
  m_coordrefval_b = crval2;
}

const double ImageParams::coordrefvalueB() const {
  return m_coordrefval_b;
}

void ImageParams::cd(const double * cd) {
  for (int i = 0; i < 4; i++) {
    m_cd->push_back(cd[i]);
  }
}

const std::vector<double> *ImageParams::cd() const {
  return m_cd;
}

std::ostream & operator<< (std::ostream & os, const ImageParams & img) {
  os << "[ImageParams]: Axis_A="          << img.ra()              << std::endl;
  os << "[ImageParams]: Axis_B="	   << img.dec()             << std::endl;
  os << "[ImageParams]: Size_A="  	   << img.size_x()          << std::endl;
  os << "[ImageParams]: Size_B="	   << img.size_y()          << std::endl;
  os << "[ImageParams]: Scale_A="	   << img.scaleA()          << std::endl;
  os << "[ImageParams]: Scale_B="	   << img.scaleB()          << std::endl;
  os << "[ImageParams]: CoordRefFrame="   << img.coordrefframe()   << std::endl;
  os << "[ImageParams]: CoordEquinox="	   << img.coordequinox()    << std::endl;
  os << "[ImageParams]: CoordProjection=" << img.coordprojection() << std::endl;
  os << "[ImageParams]: CoordRefPixel_A=" << img.coordrefpixelA()  << std::endl;
  os << "[ImageParams]: CoordRefPixel_B=" << img.coordrefpixelB()  << std::endl;
  os << "[ImageParams]: CoordRefValue_A=" << img.coordrefvalueA()  << std::endl;
  os << "[ImageParams]: CoordRefValue_B=" << img.coordrefvalueB()  << std::endl;
  
  const std::vector<double> *rot_matrix = img.cd();

  os << "[ImageParams]: CD1_1=" << rot_matrix->at(0) << std::endl;
  os << "[ImageParams]: CD1_2=" << rot_matrix->at(1) << std::endl;
  os << "[ImageParams]: CD2_1=" << rot_matrix->at(2) << std::endl;
  os << "[ImageParams]: CD2_2=" << rot_matrix->at(3) << std::endl;
  
  return os;
}
