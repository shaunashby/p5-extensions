//____________________________________________________________________ 
// File: ISGRI.h
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-08-10 15:33:54+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef ISGRI_H
#define ISGRI_H

#include "Instrument.h"

namespace Pix {
  class Process;
  class ISGRI: public Instrument {
  public:
    ISGRI();
    virtual ~ISGRI() throw();
    
    virtual void process(Process * proc);
    const Process * process() const;

  private:
    Process *m_process;
    
  private:
    ISGRI(const ISGRI & r);
    ISGRI & operator=(const ISGRI & r);
  };
}

#endif // ISGRI_H
