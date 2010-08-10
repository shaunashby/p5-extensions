// Factory class for returning instrument-specific processing object instances:

#ifndef FACTORY_H
#define FACTORY_H

namespace Pix {
  class Instrument;

  class Factory {
  public:
    static Instrument* createInstrument(const char *instrument);
  private:
    Factory(); 
  };
}

#endif
