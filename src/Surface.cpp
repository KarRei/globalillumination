#include "Surface.h"

//constructor
//Add surface properties / reflections
Surface::Surface()
{
}
Surface::Surface(ColorDbl c, float brdf)
{
    color = c;
    BRDF = brdf;
}

//destructor
Surface::~Surface()
{

}

ColorDbl Surface::getColor () {
    return color;
}

float Surface::getBRDF()
{
    return BRDF;
}
