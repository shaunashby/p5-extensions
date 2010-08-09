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

class Instrument {
public:
  Instrument();
  virtual ~Instrument();

  // Public methods:
  void process(Process & p);

private:
  Instrument(const Instrument& r);
  Instrument& operator=(const Instrument& r);

};

#endif // INSTRUMENT_H        
