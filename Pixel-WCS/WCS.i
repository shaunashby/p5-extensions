%module "Pixel::WCS"
%{
#include "WCS.h"
#include "Projections.h"
#include "Projection.h"
%}
%include "std_string.i"
%include "std_vector.i"

%include "WCS.h"
%include "Projections.h"
%include "Projection.h"

%template(projectionVector) std::vector<Projection*>;
