//____________________________________________________________________ 
// File: Utilities.h
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-29 13:02:24+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------

extern "C" {
  double wcsdist(double, double, double, double);

  void wcscon(int sys1, int sys2,
	      double eq1, double eq2,
	      double *dtheta, double *dphi, double epoch);
  
  void pix2wcs (struct WorldCoor *wcs,
		double xpix,
		double ypix,
		double *xpos,
		double *ypos);
  
  void wcs2pix (struct WorldCoor *wcs,
		double xpos,
		double ypos,
		double *xpix,
		double *ypix,
		int *offscl);
}

// Utils namespace:
namespace utils {
  double angular_distance(double & fromRA,
			  double & fromDEC,
			  double & toRA,
			  double & toDEC);
  
  void cs_convert(int in, int out, double & axisA, double & axisB);
  
  void world_to_pixel(struct WorldCoor *wcs,
		      double axis_a, double axis_b, 
		      double *x_pos, double *y_pos,
		      int x_off=0, int y_off=0);
  
  void pixel_to_world(struct WorldCoor *wcs,
		      double x_pos, double y_pos,
		      double *axis_a, double *axis_b,
		      int x_off=0, int y_off=0);
  
  void pixel_size(struct WorldCoor* wcs,
		  double x_centre, double y_centre,
		  double & x_size, double & y_size,
		  int x_off=0, int y_off=0);
}
