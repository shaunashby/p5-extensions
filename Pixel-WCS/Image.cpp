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

Image::Image(std::string & path)
  : m_path(path)
{}

Image::~Image(){
  delete [] m_cd;
}

const char * Image::ctype1() const {
  return m_ctype1;
}

const char * Image::ctype2() const {
  return m_ctype2;
}

double Image::crpix1() const {
  return m_crpix1;
}

double Image::crpix2() const {
  return m_crpix2;
}

double Image::crval1() const {
  return m_crval1;
}

double Image::crval2() const {
  return m_crval2;
}

const double * Image::cd() const {
  return m_cd;
}

double Image::lambda() const {
  return m_lambda;
}

long Image::equinox() const {
  return m_equinox;
}

const char * Image::refframe() const {
  return m_refframe;
}

