//____________________________________________________________________ 
// File: Finder.cpp
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-09 09:28:30+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include <cstdio>
#include "Finder.h"

Finder::Finder(char* base, char* instrument, int verbosity) {
  m_base = base;
  m_instrument = instrument;
  m_verbosity = verbosity;
  m_index = 0;
  m_status = 0;
  m_numrows = 0;
  m_strlength = 0;
  
  // Initialize:
  _init();
}

Finder::~Finder() {
  if (m_verbosity > 0)
    printf("~Finder(): cleaning up.\n");

  delete [] m_ra;
  delete [] m_dec;
  delete [] m_srcid;

}

char * Finder::nearest(double ra, double dec, double radius) {
  char *srcid="";
  // Dump the values we have:
  for (int i = 0; i < m_numrows; i++) {
    printf("%04d   %lf\t%lf\t%s\n",i,m_ra[i],m_dec[i],m_srcid[i]);
  }

 
  return srcid;
}

void Finder::_init() {
  sprintf(m_indexDOL, "%s/light_curves/%s/%s_index.fits[1]",
	  m_base, m_instrument, m_instrument);
  if (m_verbosity > 0)
    printf("Reading index at %s\n",m_indexDOL);

  // Open the file:
  m_status = DALobjectOpen(m_indexDOL, &m_index, m_status);

  if (m_status) {
    printf("ERROR: Unable to open file %s",m_indexDOL);
  } else {    
    
    m_status = DALtableGetNumRows(m_index, &m_numrows, m_status);

    if (m_status != 0 || m_numrows == 0) {
      printf("WARN: Index file %s has 0 rows", m_indexDOL);
      DALobjectClose(m_index, DAL_SAVE, 0);
      m_status = 999;
    }
    
    if (m_verbosity > 0)
      printf("Index file %s opened with %li rows\n",m_indexDOL,m_numrows);

    // Read the RA_OBJ column
    char columnName[30];
    dal_dataType dataType = DAL_DOUBLE;

    m_ra = new double[m_numrows];
    strcpy(columnName, "RA_OBJ");
    m_status = DALtableGetCol(m_index, columnName, 0, &dataType, NULL, m_ra, m_status);
    
    if (m_status != 0) {
      printf("ERROR: Failed to read column %s", columnName);
    } else {
      if (m_verbosity > 0) {
	printf("Column %s read.\n",columnName);
      }
    }

    // Read the DEC_OBJ column:
    m_dec = new double[m_numrows];
    strcpy(columnName, "DEC_OBJ");
    m_status = DALtableGetCol(m_index, columnName, 0, &dataType, NULL, m_dec, m_status);
    
    if (m_status != 0) {
      printf("ERROR: Failed to read column %s", columnName);
    } else {
      if (m_verbosity > 0) {
	printf("Column %s read.\n",columnName);
      }
    }

    // Handle memory allocation for the column of source IDs which are strings:
    strcpy(columnName, "SRC_ID");
    // Get the string lenght:
    m_status = DALtableGetStringLength(m_index, columnName, 0, &m_strlength, m_status);
    m_srcid= NULL;
    
    // Populate the array of source IDs:
    m_status = DALallocateStringBuffer(&m_srcid, m_numrows, m_strlength, m_status);

    if (m_status != 0) {
      printf("ERROR: Failed to allocate buffer for column %s", columnName);
    } else {
      if (m_verbosity > 0) {
	printf("Buffer for column %s allocated.\n", columnName);
	printf("Length of strings of column %s = %li.\n", columnName, m_strlength);
      }
    }

    long nstrings = 0;
    m_status = DALtableGetColStrings(m_index, columnName, 0, 1, m_numrows, &nstrings, m_srcid, m_status);
    
    if (m_status != 0) {
      printf("ERROR: Failed to read column %s", columnName);
    } else {
      if (m_verbosity > 0) {
	printf("Column %s read.\n",columnName);
      }
    }
  }
}
