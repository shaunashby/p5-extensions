//____________________________________________________________________
// File: Projections.h
//____________________________________________________________________
//
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-22 15:43:57+0200
// Revision: $Id$
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef PROJECTIONS_H
#define PROJECTIONS_H

#include <vector>

class Projection;

class Projections {
public:
  typedef std::vector<Projection *>::const_iterator SkyRegionConstIter;
public:
  Projections(const char *basedir, const char* instrument);
  virtual ~Projections();

  char * coordsystem();
  Projection * find_region(double axis_ra, double axis_dec) const;
  
  const std::vector<Projection *> * regions() const;

private:
  void _init();

private:
  const char* m_basedir;
  const char* m_instrument;

  int   m_verbosity;
  char  m_indexDOL[1024];

  int m_status;
  long m_numrows;
  long m_strlength;

  char m_coord[40];

  std::vector<Projection *> *m_projections;
};

#endif // PROJECTIONS_H
