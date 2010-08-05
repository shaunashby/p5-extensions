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

// New class declaration:
class Genpix {
public:
  Genpix();
  virtual ~Genpix() throw();
  
  // Public methods:
  void readimage(const char *image);
  void save();
  
private:  
  Genpix(const Genpix& r);
  Genpix& operator=(const Genpix& r);
  
};

#endif // GENPIX_H            
