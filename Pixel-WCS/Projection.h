//____________________________________________________________________
// File: Projection.h
//____________________________________________________________________
//
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-19 14:07:18+0200
// Revision: $Id$
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef PROJECTION_H
#define PROJECTION_H

#include <string>

class Projection {
public:
  Projection(std::string name, double a_min, double a_max, double b_min, double b_max);

  virtual ~Projection();

  std::string name() const;

  bool inside(double axis_a, double axis_b);

  double border_distance(double axis_a, double axis_b);

  inline double amin() const { return m_amin; }
  inline double amax() const { return m_amax; }
  
  inline double bmin() const { return m_bmin; }
  inline double bmax() const { return m_bmax; }

private:
  std::string m_name;
  double m_amin, m_amax, m_bmin, m_bmax;
};

#endif // PROJECTION_H
