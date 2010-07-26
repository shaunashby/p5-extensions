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

class WCS {
public:
  WCS(const char *basedir, const char *instrument);
  
  virtual ~WCS();
  
  const char * basedir() const;
  const char * instrument() const;
  
  Projections * projections() const;
  void search(double caxis_a, double caxis_b, char *coordsystem);
  
private:
  Projections *m_projections;
  
  const char *m_basedir;
  const char *m_instrument;

  double m_axis_ra;
  double m_axis_dec;

  int m_size_ra;
  int m_size_dec;
  
};

#endif // WCS_H
