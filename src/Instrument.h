//
// Instrument-specific processing class
//
//
#ifndef INSTRUMENT_H
#define INSTRUMENT_H 1

namespace PX {
  class Process {
  public:
    Process() {};
    virtual ~Process() {};
    virtual void run() = 0;
  };

  class ISGRI: public Process {
  public:
    ISGRI();
    virtual ~ISGRI();
    void run();
  };
}

#endif
