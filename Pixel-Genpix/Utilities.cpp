//____________________________________________________________________ 
// File: Utilities.cpp
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-29 14:17:08+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include "Utilities.h"

namespace utils {
  double angular_distance(double & fromRA,
			  double & fromDEC,
			  double & toRA,
			  double & toDEC) {
    return ::wcsdist(fromRA, fromDEC, toRA, toDEC);
  }
  
  void cs_convert(int in, int out, double & axisA, double & axisB) {
    ::wcscon(in, out, 2000, 2000, &axisA, &axisB, 0);
  }
  
  void world_to_pixel(struct WorldCoor *wcs,
		      double axis_a, double axis_b, 
		      double *x_pos, double *y_pos,
		      int x_off, int y_off) {
    int offs;
    ::wcs2pix(wcs, axis_a, axis_b, x_pos, y_pos, &offs);
    // x/y positions now in reference image
    *x_pos -= x_off;
    *y_pos -= y_off;
    // x/y positions now in required image
  }
  
  void pixel_to_world(struct WorldCoor *wcs,
		      double x_pos, double y_pos,
		      double *axis_a, double *axis_b,
		      int x_off, int y_off) {
    // x/y positions now in required image
    x_pos += x_off;
    y_pos += y_off;
    // x/y positions now in reference image
    ::pix2wcs(wcs, x_pos, y_pos, axis_a, axis_b);
  }
  
  void pixel_size(struct WorldCoor *wcs,
		  double x_centre,
		  double y_centre,
		  double & x_size,
		  double & y_size,
		  int x_off, int y_off) {
    double p1a, p1b, p2a, p2b;  // axis A and B of point 1 and 2

    pixel_to_world(wcs,
		   x_centre - 0.5, y_centre, &p1a, &p1b,
		   x_off, y_off);
    pixel_to_world(wcs,
		   x_centre + 0.5, y_centre, &p2a, &p2b,
		   x_off, y_off);
    x_size = ::wcsdist(p1a, p1b, p2a, p2b);

    pixel_to_world(wcs,
		   x_centre, y_centre - 0.5, &p1a, &p1b,
		   x_off, y_off);
    pixel_to_world(wcs,
		   x_centre, y_centre + 0.5, &p2a, &p2b,
		   x_off, y_off);
    y_size = ::wcsdist(p1a, p1b, p2a, p2b);
  }
}
