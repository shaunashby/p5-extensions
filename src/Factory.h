// Factory class for returning instrument-specific processing object instances:

#ifndef FACTORY_H
#define FACTORY_H

#include "ProcType.h"

namespace PX {
  class Process;

  class Factory {
  public:
    static Process* create(PX::INST::ID inst_id);
  };
}

#endif
