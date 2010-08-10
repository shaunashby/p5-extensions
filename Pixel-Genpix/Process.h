//____________________________________________________________________ 
// File: Process.h
//____________________________________________________________________ 
//  
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-08-09 12:33:56+0200
// Revision: $Id$ 
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#ifndef PROCESS_H           
#define PROCESS_H           

namespace Pix {
  class Process {
  public:
    virtual ~Process() {} throw();
    virtual void initialize() = 0;
    virtual void run() = 0;
  private:
    Process(const Process& r);
    Process & operator=(const Process& r);
  };
}
#endif // PROCESS_H           
