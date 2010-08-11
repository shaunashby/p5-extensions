//____________________________________________________________________ 
// File: Genpix.cpp
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-08-05 15:17:37+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include <iostream>

#include "Genpix.h"
#include "Factory.h"
#include "Instrument.h"
#include "Image.h"

Genpix::Genpix(char *inIMG, char *refimage, double lowL, double highL, double lowB, double highB, int oversample)
try : m_instrument(0) {
  
  // Create reference image containing WCS parameters:
  std::cout << "[Genpix]: Ref image =" << refimage << std::endl;
  Pix::Image refImage(refimage);

  std::cout << "[Genpix]: Processing for instrument " << refImage.instrument() << " will be run." << std::endl;
  
  m_instrument = Pix::Factory::createInstrument(refImage.instrument());
  m_instrument->setup(inIMG,refImage, lowL, highL, lowB, highB, oversample);
  
  // Run the processing:
  m_instrument->run_loop();
  
      } catch ( ... ) { std::cerr << "Genpix::Genpix: ERROR in member initialization." << std::endl; }


Genpix::~Genpix() throw(){
  delete m_instrument;
}

void Genpix::save(){
  m_instrument->write();
}

const char* Genpix::version() const {
  return GENPIX_VERSION;
}
