//____________________________________________________________________
// File: WCS.h
//____________________________________________________________________
//
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-19 12:13:05+0200
// Revision: $Id$
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef WCS_H
#define WCS_H

class Projections;
class ImageParams;

class WCS {
public:
  WCS(const char *basedir, const char *instrument);
  
  virtual ~WCS();
  
  const char * basedir() const;
  const char * instrument() const;
  
  Projections * projections() const;
  void search(double caxis_a, double caxis_b, char *coordsystem, int size_x=20, int size_y=20);
  ImageParams *params() const;

private:
  Projections *m_projections;
  ImageParams *m_image_params;
  
  const char *m_basedir;
  const char *m_instrument;

  double m_axis_ra;
  double m_axis_dec;

  int m_size_x;
  int m_size_y;
  
};

#endif // WCS_H
