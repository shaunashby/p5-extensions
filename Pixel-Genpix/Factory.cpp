// Factory to return instrument-specific processing object:

#include "Factory.h"
#include "Instrument.h"
#include "ISGRI.h"

//#define ALL_INSTRUMENTS 1

// Factory class to create instrument-specific classes
namespace Pix {
  Instrument* Factory::createInstrument(const char * instrument) {
    if (instrument == "ISGRI") {
      return new ISGRI();
#ifdef ALL_INSTRUMENTS
    } else if (instrument == "JEMX") {
      return new JEMX();
    } else if (instrument == "BAT") {
      return new BAT();
    } else if (instrument == "SPI_ACS") {
      return new SPI_ACS();
#endif
    } else {
      // Error state. Return 0 for now but need exceptions:
      return 0;
    }
  }
}

    
