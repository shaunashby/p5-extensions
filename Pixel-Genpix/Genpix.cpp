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
#include <sstream>

#include "Genpix.h"
#include "Factory.h"
#include "Instrument.h"

class Error;

Genpix::Genpix(char *image, char *refimage, double lowL, double highL, double lowB, double highB, int oversample)
try : m_image(image),
	m_refimage(refimage),
	m_lowL(lowL),
	m_highL(highL),
	m_lowB(lowB),
	m_highB(highB),
	m_oversample(oversample),m_instrument(0) {
  // Read reference image:
  
  
  
	} catch ( ... ) { std::cerr << "Genpix::Genpix: ERROR in member initialization." << std::endl; }

Genpix::~Genpix() throw()
{}

void Genpix::read_reference(){
  std::cout << "Reading reference image " << m_refimage << std::endl;




  
  // Get instrument (eventually from the reference image FITS file:
  const char * instrument = "ISGRI";
  m_instrument = Pix::Factory::createInstrument(instrument);

  if (m_instrument == 0) {
    // Error state: unknown instrument:
    std::cerr << "ERROR: Unknown instrument " << instrument << std::endl;
  }

  delete m_instrument;
  
}

void Genpix::save(){
}

const char* Genpix::version() const {
  return GENPIX_VERSION;
}

const std::string Genpix::print() const {
  std::stringstream O(std::stringstream::out);
  O << "lowL         -- " << m_lowL        << "\n"; 
  O << "highL        -- " << m_highL       << "\n";
  O << "lowB         -- " << m_lowB        << "\n";
  O << "highB        -- " << m_highB       << "\n";
  O << "refImage     -- " << m_refimage    << "\n";
  O << "overSampling -- " << m_oversample  << "\n";
  return std::string(O.str());
}

std::ostream & operator<< (std::ostream & O, const Genpix & o) {
  O << o.print();
  return O;
}
