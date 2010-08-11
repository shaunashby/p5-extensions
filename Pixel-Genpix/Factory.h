// Factory class for returning instrument-specific processing object instances:

#ifndef FACTORY_H
#define FACTORY_H

#include <string>

namespace Pix {
  class Instrument;

  class Factory {
  public:
    static Instrument* createInstrument(std::string instrument);
  private:
    Factory(); 
  };
}

#endif
