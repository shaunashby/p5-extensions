//____________________________________________________________________ 
// File: IBISImage.h
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-26 15:48:16+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef IBISIMAGE_H             
#define IBISIMAGE_H             

#include <string>

#include "Image.h"

struct WorldCoor;

namespace Pix {
  class IBISImage: public Image {
  public:
    IBISImage(std::string & path);
    IBISImage(const char *path);
    
    IBISImage(const Image & i);
    
    virtual ~IBISImage();
    
    // Public methods:
    const char * instrument() const;
    
    const double * cd() const;

    const int size_x() const;
    const int size_y() const;
    
    WorldCoor* wcs() const;
    
  private:
    // Function to read the FITS image file to
    // obtain values to initialize the object:
    void _init(const char * path);
    
  private:
    WorldCoor *m_wcs;
    
    int m_sizex;
    int m_sizey;
    
    double   m_cd[4];

  };
}

#endif // IBISIMAGE_H
