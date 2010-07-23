// Factory to return instrument-specific processing object:

#include "Factory.h"
#include "Instrument.h"

PX::Process* PX::Factory::create(PX::INST::ID id) {
  switch (id) {
  case PX::INST::ISGRI:
    return new PX::ISGRI();
    break;
  case PX::INST::JEMX:
    return 0;
    break;
  case PX::INST::BAT:
    return 0;
    break;
  case PX::INST::SPI_ACS:
    return 0;
    break;
  default:
    return 0;
    break;
  }
}

