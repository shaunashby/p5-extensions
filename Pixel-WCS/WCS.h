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

#include <string>
#include <vector>

class Projection;

class WCS {
public:
  WCS(std::string & basedir, std::string & instrument);

  virtual ~WCS();

  std::string & basedir() const;
  std::string & instrument() const;

  std::vector<Projection *> * projections() const;

private:
  std::vector<Projection*> *m_projections;

  std::string & m_basedir;
  std::string & m_instrument;

  double m_axis_ra;
  double m_axis_dec;

  int m_size_ra;
  int m_size_dec;

};

#endif // WCS_H
