//____________________________________________________________________
// File: Projection.cpp
//____________________________________________________________________
//
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-22 15:49:47+0200
// Revision: $Id$
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include "Projection.h"
#include <iostream>
#include <cmath>

Projection::Projection(std::string name, double a_min, double a_max, double b_min, double b_max)
  : m_name(name),
    m_amin(a_min),
    m_amax(a_max),
    m_bmin(b_min),
    m_bmax(b_max)
{}

Projection::~Projection(){}

std::string Projection::name() const {
  return m_name;
}

bool Projection::inside(double axis_a, double axis_b) {
  if (axis_b < m_bmin || axis_b > m_bmax)
    return false;

  while (axis_a < 0)
    axis_a += 360;
  while (axis_a >= 360)
    axis_a -= 360;

  if (fabs(m_amin - m_amax) < 0.1)
    return true;

  if (m_amin > m_amax) {
    return axis_a >= m_amin || axis_a <= m_amax;
  } else {
    return axis_a >= m_amin && axis_a <= m_amax;
  }
}

double Projection::border_distance(double axis_a, double axis_b) {
  // Max is 180 deg if full sky image:
  double distance = 180;

  if (m_bmin > -90.0 + 0.001) {
    if (axis_b - m_bmin < distance) distance = axis_b - m_bmin;
  }

  if (m_bmax < 90.0 - 0.001) {
    if (m_bmax - axis_b < distance) distance = m_bmax - axis_b;
  }

  while (axis_a < 0)
    axis_a += 360;

  while (axis_a >= 360)
    axis_a -= 360;

  if (fabs(m_amin - m_amax) > 0.1  ) {
    double cosB = cos(axis_b / 180 * 3.14159265358);
    double thisDis = fabs(axis_a - m_amin);

    if (thisDis > 180) thisDis = 360 - thisDis;
    if ( thisDis * cosB < distance)   distance = thisDis * cosB;

    thisDis = fabs(axis_a - m_amax);
    if (thisDis > 180) thisDis = 360 - thisDis;
    if ( thisDis * cosB < distance)   distance = thisDis * cosB;
  }

  return distance;
}
