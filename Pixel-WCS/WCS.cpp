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
#include "Utilities.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

extern "C" {
  int wcscsys(char *coorsys);
  void wcscon(int sys1, int sys2, double eq1, double eq2, double *dtheta, double *dphi, double epoch);
}

WCS::WCS(const char * basedir, const char * instrument){
  m_basedir = basedir;
  m_instrument = instrument;
  m_projections = new Projections(m_basedir, m_instrument);
  m_axis_ra = 0.;
  m_axis_dec = 0.;
  m_size_x = 0;
  m_size_y = 0;
}

WCS::~WCS() {
  delete m_projections;
}

void WCS::search(double axis_a, double axis_b, char *coords, int size_x, int size_y) {
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
    utils::cs_convert(inputCoordsID, fileCoordsID, axis_a, axis_b);

    m_axis_ra = axis_a;
    m_axis_dec = axis_b;
  }

  // Get the name of the projection region:
  Projection * pRegion = m_projections->find_region(m_axis_ra, m_axis_dec);

  if (pRegion == 0) {
    // FIXME: handle with exceptions
    std::cerr << "[WCS::search]: No region found. Not enough data." << std::endl;
    return;
  }
  
  // Open reference image for the region:
  std::stringstream p;
  p << m_basedir << "/pixels/" << m_instrument  << "/" << pRegion->name();
  p << "/" << pRegion->name() << "_" << m_instrument << ".fits[1]";
  std::string path = p.str();
  
  Image * refimage = new Image(path);

  // For the required image:
  double pos_x, pos_y;
  utils::world_to_pixel(refimage->wcs(), axis_a, axis_b, &pos_x, &pos_y);

  // Calculate offsets for the required image:
  int x_off = (int)(pos_x - size_x / 2.0);
  int y_off = (int)(pos_y - size_y / 2.0);

  // Get the centre of the image:
  double centre_ra, centre_dec;
  utils::pixel_to_world(refimage->wcs(),
			size_x / 2.0 + 0.5,
			size_y / 2.0 + 0.5,
			&centre_ra, &centre_dec, x_off, y_off);

  std::cout << "[WCS::search]: Pixel number of centre: " << pos_x << "/" << pos_y << std::endl;

  utils::cs_convert(fileCoordsID, inputCoordsID, centre_ra, centre_dec);

  std::cout << "[WCS::search]: Image centre @ (RA) " << centre_ra << "/ (DEC) " << centre_dec << std::endl;

  // Get pixel size:
  double pixel_size_x, pixel_size_y;
  utils::pixel_size(refimage->wcs(),
		    size_x / 2.0 + 0.5,
		    size_y / 2.0 + 0.5,
		    pixel_size_x, pixel_size_y, x_off, y_off);

  printf("Axis_A=%.6f\n", centre_ra);
  printf("Axis_B=%.6f\n", centre_dec);
  printf("Size_A=%d\n", size_x);
  printf("Size_B=%d\n", size_y);
  printf("Scale_A=%lf\n", pixel_size_x);
  printf("Scale_B=%lf\n", pixel_size_y);
  printf("CoordRefFrame=%s\n", refimage->refframe());
  printf("CoordEquinox=%d\n",  refimage->equinox());
  printf("CoordProjection=%s\n",  refimage->ctype1());
  printf("CoordRefPixel_A=%.1lf\n", refimage->crpix1() - x_off);
  printf("CoordRefPixel_B=%.1lf\n", refimage->crpix2() - y_off);
  printf("CoordRefValue_A=%lf\n", refimage->crval1());
  printf("CoordRefValue_B=%lf\n", refimage->crval2());
  const double * cd = refimage->cd();
  printf("CD1_1=%.16lf\n", cd[0]);
  printf("CD1_2=%.16lf\n", cd[1]);
  printf("CD2_1=%.16lf\n", cd[2]);
  printf("CD2_2=%.16lf\n", cd[3]);
  
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
