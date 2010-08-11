%module "Pixel::Genpix"
%{
#include "Genpix.h"
%}
%include "std_string.i"
%include "std_vector.i"
%include "typemaps.i"

%include "Genpix.h"

%template(Vec)   std::vector<void*>;
%template(Array) std::vector<double>;
