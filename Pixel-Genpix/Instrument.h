//____________________________________________________________________ 
// File: Instrument.h
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-08-09 13:32:50+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef INSTRUMENT_H        
#define INSTRUMENT_H        

namespace Pix {
  class Process;
  
  class Instrument {
  public:
    virtual ~Instrument() {};
    // Set and get methods for the instrument processing class:
    virtual void process(Process *p) = 0;
    const virtual Process * process() const = 0;
  };
}

#endif // INSTRUMENT_H        
