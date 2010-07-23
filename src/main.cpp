// A simple main program to test code before
// wrapping for use with Perl:
#include <iostream>

#include "Projection.h"
#include "Projections.h"

#include <algorithm>
#include <functional>

template <class T> struct Show: public std::unary_function<T, void> {
  Show(std::ostream & out)
    : m_out(out)
  {}
  
  void operator() (T p) { m_out << "\t" << p->name() << "\n"; }
  
  std::ostream & m_out;
};

int main(int argc, char *argv[]) {
  // Get the projections:
  Projections *proj = 0;
  
  if (argc > 1) {
    std::cout << "Getting projection information for " << argv[2] << std::endl;
    proj = new Projections(argv[1],argv[2]);
    
    std::size_t n_regions = proj->regions()->size();
    
    std::cout << "Got " << n_regions << " sky regions:" << std::endl;
    
    Projections::SkyRegionConstIter first = proj->regions()->begin();
    Projections::SkyRegionConstIter last  = proj->regions()->end();
    
    std::for_each(first,last,Show<Projection *>(std::cout));
    
    delete proj;
  } else {
    std::cerr << "Require base dir and instrument name arguments!" << std::endl;
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
