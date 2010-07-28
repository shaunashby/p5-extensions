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

Image::Image(std::string & path)
  : m_wcs(0), m_sizex(20), m_sizey(20) /* Default image sizes */ {
  _init(path);
}

Image::~Image(){
  std::cout << "~Image: bye." << std::endl;
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

const int Image::size_x() const {
  return m_sizex;
}

const int Image::size_y() const {
  return m_sizey;
}

void Image::_init(std::string & path) {
  dal_element *image;
  int m_status = 0;

  m_status = DALobjectOpen(path.c_str(), &image, m_status);
  
  if (m_status != 0) {
    std::cerr << "[Image]: Unable to open " << path << std::endl;
    DALobjectClose(image, DAL_SAVE, 0);
    m_status = -36270;
    return;
  } else {
    std::cout << "[Image]: Reading " << path << std::endl;
  }
  
  // Populate the data members from the data within the FITS image file:
  m_status = DALattributeGet(image, "CTYPE1", DAL_CHAR, m_ctype1, NULL, NULL, m_status);
  
  char errAttr[20] = "";
  if (m_status != 0)
    strcpy(errAttr, "CTYPE1");
  
  std::cout << errAttr << std::endl;
  
  if (m_status != 0) {
    std::cout << "ERROR: Failed to read attribute from FITS image file." << std::endl;
    DALobjectClose(image, DAL_SAVE, 0);
    return;
  }
  
  std::cout << "Here...?" << std::endl;
  
  //   m_status = DALattributeGet(image, "CTYPE2", DAL_CHAR, m_ctype2, 
  // 			     NULL, NULL, m_status);
//     if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }

//   m_status = DALattributeGet(image, "CRVAL1", DAL_DOUBLE, &m_crval1,
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "CRVAL2", DAL_DOUBLE, &m_crval2,
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "CD1_1", DAL_DOUBLE, &m_cd[0], 
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "CD1_2", DAL_DOUBLE, &m_cd[1], 
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "CD2_1", DAL_DOUBLE, &m_cd[2], 
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "CD2_2", DAL_DOUBLE, &m_cd[3], 
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "RADECSYS", DAL_CHAR, m_refframe, 
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "EQUINOX", DAL_LONG, &m_equinox, 
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "SIZE1", DAL_LONG, &m_sizex, 
// 			     NULL, NULL, m_status);
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }
  
//   m_status = DALattributeGet(image, "SIZE2", DAL_LONG, &m_sizey, 
// 			     NULL, NULL, m_status);  
  
//   if (m_status != 0) {
//     std::cerr << "ERROR: Failed to read attribute from FITS image file." << std::endl;
//     DALobjectClose(image, DAL_SAVE, 0);
//     return;
//   }

  // Close the table:
  //DALobjectClose(image, DAL_SAVE, 0);
}
