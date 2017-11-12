#include "Surface.h"

//constructor
//Add surface properties / reflections
Surface::Surface()
{
}
Surface::Surface(ColorDbl c, int m)
{
    color = c;
    //BRDF = brdf;
    model = m;
    //emission = e;
}

//destructor
Surface::~Surface()
{

}

ColorDbl Surface::getColor () {
    return color;
}

int Surface::getModel()
{
    return model;
}
