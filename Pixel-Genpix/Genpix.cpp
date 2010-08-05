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
#include <stdexcept>

Genpix::Genpix(){

}

Genpix::~Genpix() throw() {
}

void Genpix::readimage(const char *image){
  std::cout << "Reading image " << image << std::endl;
}

void Genpix::save(){
}

