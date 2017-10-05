#include "ColorDbl.h"

ColorDbl::ColorDbl()
{
    color = glm::vec3(0.0f);
}

ColorDbl::ColorDbl(glm::vec3 a)
{
    color = a;
}

ColorDbl::~ColorDbl()
{
    //dtor
}
