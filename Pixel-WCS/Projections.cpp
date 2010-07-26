//____________________________________________________________________
// File: Projections.cpp
//____________________________________________________________________
//
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-22 15:43:42+0200
// Revision: $Id$
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include "Projections.h"
#include "Projection.h"

#include <iostream>

Projections::Projections(const char *basedir, const char* instrument) {
  m_basedir = basedir;
  m_instrument = instrument;
  m_numrows = 0;
  m_projections = 0;
  m_status = 0;
  // Call init function:
  this->_init();
}

Projections::~Projections(){
  std::vector<Projection *>::iterator region = m_projections->begin();
  std::vector<Projection *>::iterator end = m_projections->end();
  
  for (region; region != end; ++region) {
    delete *region;
  }
  
  delete m_projections;
}

void Projections::_init() {
  sprintf(m_indexDOL, "%s/pixels/%s/projection.fits[1]",m_basedir, m_instrument);
  
  dal_element * table;
  m_status = DALobjectOpen(m_indexDOL, &table, m_status);         // Open the table
  m_status = DALtableGetNumRows(table, &m_numrows, m_status);     // Get the number of rows
  
  if (m_status != 0 || m_numrows == 0) {
    std::cerr << "Projections::_init: table has only " << m_numrows << " rows." << std::endl;
    DALobjectClose(table, DAL_SAVE, 0);
    m_status = -36270;
    return;
  } else {
    std::cout << "[Projections]: Reading " << m_numrows << " rows from " << m_indexDOL << std::endl;
  }
  
  // Allocate memory for the table given the number of strings contained
  // within it:
  m_status = DALtableGetStringLength(table, "PROJ_NAME", 0, &m_strlength, m_status);
  
  char ** prj_name = NULL;
  m_status = DALallocateStringBuffer(&prj_name, m_numrows, m_strlength, m_status);
  
  double * axa_min = new double[m_numrows];
  double * axa_max = new double[m_numrows];
  double * axb_min = new double[m_numrows];
  double * axb_max = new double[m_numrows];
  
  // Read the columns of data:
  long num_strings;
  m_status = DALtableGetColStrings(table, "PROJ_NAME", 0, 1, m_numrows,
				   &num_strings, prj_name, m_status);
  
  dal_dataType dataType = DAL_DOUBLE;
  m_status = DALtableGetCol(table, "AXIS_1_MIN", 0, &dataType, NULL, axa_min, m_status);

  dataType = DAL_DOUBLE;
  m_status = DALtableGetCol(table, "AXIS_1_MAX", 0, &dataType, NULL, axa_max, m_status);

  dataType = DAL_DOUBLE;
  m_status = DALtableGetCol(table, "AXIS_2_MIN", 0, &dataType, NULL, axb_min, m_status);

  dataType = DAL_DOUBLE;
  m_status = DALtableGetCol(table, "AXIS_2_MAX", 0, &dataType, NULL, axb_max, m_status);

  // Store projections:
  if (m_status == 0) {
    m_projections = new std::vector<Projection *>();
    
    for (int row = 0; row < m_numrows; row++) {
      if (axa_min[row] < 0)    axa_min[row] += 360;
      if (axa_max[row] >= 360) axa_max[row] -= 360;
      std::string region(prj_name[row]);
      m_projections->push_back(new Projection(prj_name[row], axa_min[row], axa_max[row], axb_min[row], axb_max[row]));
    }
  }

  DALfreeStringBuffer(prj_name, m_numrows, m_status);

  delete [] axa_min;
  delete [] axa_max;
  delete [] axb_min;
  delete [] axb_max;
  
  if (m_status != 0) {
    DALobjectClose(table, DAL_SAVE, 0);
    return;
  }
  
  // Get coord system associated with FITS file:
  m_status = DALattributeGet(table, "COORDSYS", DAL_CHAR, m_coord, NULL, NULL, m_status);
  
  if (m_status != 0) {
    std::cerr << "ERROR: Failed to read COORDSYS from table in projection file." << std::endl;
    DALobjectClose(table, DAL_SAVE, 0);
    return;
  }
  
  // Close the table:
  DALobjectClose(table, DAL_SAVE, 0);
}

char *Projections::coordsystem() {
  return m_coord;
}

Projection * Projections::find_region(double axis_ra, double axis_dec) const {
  // Find the best-fit region for the converted input coordinates
  std::vector<Projection *>::iterator best = m_projections->end();

  double this_x = 0;
  double best_x =0;

  std::vector<Projection *>::iterator region = m_projections->begin();
  std::vector<Projection *>::iterator end = m_projections->end();
  
  for (region; region != end; region++) {
    if ((*region)->inside(axis_ra, axis_dec)) {
      this_x = (*region)->border_distance(axis_ra, axis_dec);
      if (this_x > best_x) {
	best_x = this_x;
	best = region;
      }
    }
  }
  
  // Return the region if foudn, otherwise return null pointer:
  if (best != m_projections->end())
    return *best;

  return 0;      
}

const std::vector<Projection *> * Projections::regions() const {
  return m_projections;
}
