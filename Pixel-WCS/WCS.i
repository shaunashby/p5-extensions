%module "Pixel::WCS"
%{
#include "WCS.h"
#include "Projections.h"
#include "Projection.h"
#include "ImageParams.h"
%}
%include "std_string.i"
%include "std_vector.i"
%include "typemaps.i"

%include "WCS.h"
%include "Projections.h"
%include "Projection.h"
%include "ImageParams.h"

%template(projectionVector) std::vector<Projection*>;
