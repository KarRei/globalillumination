#include "Surface.h"

//constructor
//Add surface properties / reflections
Surface::Surface()
{
}
Surface::Surface(ColorDbl c)
{
    color = c;
}

//destructor
Surface::~Surface()
{

}

ColorDbl Surface::getColor () {
    return color;
}
