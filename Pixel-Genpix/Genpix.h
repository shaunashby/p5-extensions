//____________________________________________________________________ 
// File: Genpix.h
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-08-05 15:11:37+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef GENPIX_H
#define GENPIX_H

// Version string:
#define GENPIX_VERSION "[Pixel::Genpix]: perl extension v0.1, perl v5.8.9, (SFA)"

namespace Pix {
  class Instrument;
}

// New class declaration:
class Genpix {
public:
  Genpix(char *inIMG, char *refimage, double lowL, double highL, double lowB, double highB, int oversample=3);
  
  virtual ~Genpix() throw();
  
  // Public methods:
  void save();
  
  const char * version() const;

private:  
  Pix::Instrument * m_instrument;
  
private:  
  Genpix(const Genpix & r);
  Genpix & operator=(const Genpix & r);
};

/*

Main Genpix class

- read reference image to determine which instrument to use

- set up instance of instrument class
* Use factory-based approach to isolate client from the implementation

   const char *instrument;
   Instrument *inst = Processor::get(instrument);

   // Get the image list:
   inst->get_index();

   // Loop over image files:
   inst->run_loop();

   // Finish:
   inst->end_job();

*/

#endif
