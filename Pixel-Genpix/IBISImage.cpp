//____________________________________________________________________ 
// File: IBISImage.cpp
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-08-12 13:38:37+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include <iostream>

#include "IBISImage.h"
#include "dal.h"

namespace Pix {
  IBISImage::IBISImage(std::string & path) /* Default image sizes */
  try  
    : Image(path) {

    } catch ( ... ) {
    std::cerr << "[IBISImage]: error in construction - member initialization failed." << std::endl;
  }
  
  IBISImage::IBISImage(const char * path) /* Default image sizes */
  try  
    : Image(path) {
      
    } catch ( ... ) {
    std::cerr << "[IBISImage]: Error in construction - member initialization failed." << std::endl;
  }
    
  IBISImage::~IBISImage(){
  }
    
  const double * IBISImage::cd() const {
    return m_cd;
  }
    
  const int IBISImage::size_x() const {
    return m_sizex;
  }
  
  const int IBISImage::size_y() const {
    return m_sizey;
  }
  
  WorldCoor* IBISImage::wcs() const {
    return m_wcs;
  }
  
  void IBISImage::_init(const char * path) {
    // FIXME: Use exceptions
    //    dal_element *image;
    int m_status = 0;
    
    //    m_status = DALobjectOpen(path, &image, m_status);
    
    if (m_status != 0) {
      // FIXME:
      std::cerr << "[IBISImage]: Unable to open " << path << std::endl;
      //      DALobjectClose(image, DAL_SAVE, 0);
      m_status = -36270;
      return;
    }
    
    // Populate the data members from the data within the FITS image file:
//     m_status = DALattributeGet(image, "INSTRUME", DAL_CHAR, m_instrument, NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "CTYPE1", DAL_CHAR, m_ctype1, NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "CTYPE2", DAL_CHAR, m_ctype2, NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "CRVAL1", DAL_DOUBLE, &m_crval1, NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "CRVAL2", DAL_DOUBLE, &m_crval2, NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "CD1_1", DAL_DOUBLE, &m_cd[0], NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "CD1_2", DAL_DOUBLE, &m_cd[1], NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "CD2_1", DAL_DOUBLE, &m_cd[2], NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "CD2_2", DAL_DOUBLE, &m_cd[3], NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "RADECSYS", DAL_CHAR, m_refframe, NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "EQUINOX", DAL_LONG, &m_equinox, NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "SIZE1", DAL_LONG, &m_sizex, NULL, NULL, m_status);
//     m_status = DALattributeGet(image, "SIZE2", DAL_LONG, &m_sizey, NULL, NULL, m_status);  
    
//     if (m_status != 0) {
//       // FIXME:
//       std::cerr << "ERROR: Failure while reading attribute from FITS image file." << std::endl;
//       return;
//     }
    
//     m_crpix1 = m_sizex/2.0 + 0.5;
//     m_crpix2 = m_sizey/2.0 + 0.5;
    
//     // Now populate the WorldCor struct:
//     m_wcs = ::wcskinit(m_sizex, m_sizey,
// 		       m_ctype1, m_ctype2,
// 		       m_crpix1, m_crpix2,
// 		       m_crval1, m_crval2,
// 		       m_cd, 0.0, 0.0, 0.0, m_equinox, 0.0);
    
//     // Close the table:
//     DALobjectClose(image, DAL_SAVE, 0);
  }
}
