//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-08 12:09:57+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef FINDER_H
#define FINDER_H

#include "dal3gen.h"

// New class declaration:
class Finder
{
public:
  Finder(char* base, char* instrument, int verbosity);
  ~Finder();

  // Public methods:
  char * nearest(double ra, double dec, double radius);

private:
  void _init();
  
private:
  char* m_base;
  char* m_instrument;
  int   m_verbosity;
  char  m_indexDOL[1024];

  dal_element* m_index;
  int m_status;
  
  // Data members for the data read in from the FITS index:
  double *m_ra;
  double *m_dec;
  char **m_srcid;
  
  long m_numrows;
  long m_strlength;

};

#endif // FINDER_H      
