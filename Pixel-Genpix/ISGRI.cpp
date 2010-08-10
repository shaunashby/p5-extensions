//____________________________________________________________________ 
// File: ISGRI.cpp
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-08-10 15:35:34+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include "ISGRI.h"
#include <iostream>

namespace Pix {
  ISGRI::ISGRI() try 
    : m_process(0)
	{} catch( ... ) {
    std::cerr << "ISGRI: Construction failed in initialization." << std::endl;
  }
  
  ISGRI::~ISGRI() throw()
  {}
  
  void ISGRI::process(Process *proc) {
  }

  const Process * ISGRI::process() const
  {}
  
}
