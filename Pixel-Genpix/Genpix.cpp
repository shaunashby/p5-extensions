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
#include "Genpix.h"
#include <iostream>
#include <sstream>

Genpix::Genpix(char *image, char *refimage, double lowL, double highL, double lowB, double highB, int oversample)
  : m_image(image),
    m_refimage(refimage),
    m_lowL(lowL),
    m_highL(highL),
    m_lowB(lowB),
    m_highB(highB),
    m_oversample(oversample)
{}

Genpix::~Genpix() throw()
{}

void Genpix::read_reference(){
  std::cout << "Reading reference image " << m_refimage << std::endl;


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
