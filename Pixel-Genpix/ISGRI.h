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
#include <string>

namespace Pix {

  class Process;  // The processing base class
  class Image;    // For the reference image data
  
  class ISGRI: public Instrument {
  public:
    ISGRI();
    virtual ~ISGRI() throw();
    
    virtual void process(Process * proc);
    virtual const Process * process() const;
    virtual void setup(const char * inIMG, const Image & ref, double lowL, double highL, double lowB, double highB, int oversample);
    virtual void run_loop();
    virtual void write();
    
    const std::string print() const;
    
  private:
    Process *m_process;
    
    char * m_input_image;
    
    double m_lowL;
    double m_highL;
    double m_lowB;
    double m_highB;
    
    int m_oversample;
    
  private:
    ISGRI(const ISGRI & r);
    ISGRI & operator=(const ISGRI & r);
  };
}

std::ostream & operator<< (std::ostream & O, const Pix::ISGRI & o);

#endif // ISGRI_H
