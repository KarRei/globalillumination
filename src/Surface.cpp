#include "Surface.h"

//constructor
//Add surface properties / reflections
Surface::Surface()
{
}
Surface::Surface(ColorDbl c, int m)
{
    color = c;
    model = m;
    if(m == 2)
        intensity = glm::vec3(20.0f);
    else
        intensity = glm::vec3(0.0f);
}

//destructor
Surface::~Surface()
{

}

ColorDbl Surface::getColor () {
    return color;
}

glm::vec3 Surface::getIntensity()
{
    return intensity;
}

int Surface::getModel()
{
    return model;
}
