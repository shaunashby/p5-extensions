//____________________________________________________________________
// File: WCS.cpp
//____________________________________________________________________
//
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-20 11:04:47+0200
// Revision: $Id$
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include "WCS.h"
#include "Projections.h"
#include "Projection.h"
#include "Image.h"

#include <iostream>

extern "C" {
  extern int wcscsys(char *coorsys);
  extern void wcscon(int sys1, int sys2, double eq1, double eq2, double *dtheta, double *dphi, double epoch);
}

WCS::WCS(const char * basedir, const char * instrument){
  m_basedir = basedir;
  m_instrument = instrument;
  m_projections = new Projections(m_basedir, m_instrument);
  m_axis_ra = 0.;
  m_axis_dec = 0.;
}

WCS::~WCS() {
  delete m_projections;
}

void WCS::search(double axis_a, double axis_b, char *coords) {
  // Coord system according to the projection file:
  char *fileCoords = m_projections->coordsystem();

  // Use external WCS library function for the conversion. Returns an int
  // representing the identifier of the coordinate system:
  int fileCoordsID = ::wcscsys(fileCoords);
  int inputCoordsID = ::wcscsys(coords); // ID for wanted coord system of input coords

  // FIXME: Throw an exception if the returned ID is less than 0 (coord
  // system unknown to wcs library):
  if (fileCoordsID == inputCoordsID) {
    // No conversion necessary:
    m_axis_ra = axis_a;
    m_axis_dec = axis_b;
  } else {
    // Convert input coords in input coord system to coord system of the
    // reference, i.e. the projection file:
    ::wcscon(inputCoordsID, fileCoordsID, 2000, 2000, &axis_a, &axis_b, 0);
    
    m_axis_ra = axis_a;
    m_axis_dec = axis_b;

    std::cout << "[WCS::search]: Converted from coordsystem " << coords << " to " << fileCoords << std::endl;
    std::cout << "[WCS::search]: New coordinates are " << m_axis_ra << " / " << m_axis_dec << std::endl;
    
  }

  // Get the name of the projection region:
  Projection * pRegion = m_projections->find_region(m_axis_ra, m_axis_dec);

  if (pRegion != 0) {
    std::cout << "[WCS::search]: Found best region " << pRegion->name() << std::endl;
  } else {
    std::cout << "[WCS::search]: No regioin found. Not enough data." << std::endl;
  }
  
  // Open reference image for the region:
  std::string path("some_path");
  Image * refimage = new Image(path);

  delete refimage;
}

const char * WCS::basedir() const {
  return m_basedir;
}

const char * WCS::instrument() const {
  return m_instrument;
}

Projections * WCS::projections() const {
  return m_projections;
}
