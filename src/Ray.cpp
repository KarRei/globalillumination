#include "Ray.h"

Ray::Ray()
: rayStart(glm::vec3(0.0f)), rayPoint(glm::vec3(0.0f))
{ }

Ray::Ray(glm::vec3 s, glm::vec3 e)
: rayStart(s), rayPoint(e)
{ }

Ray::~Ray()
{
    //dtor
}

glm::vec3 Ray::getStart()
{
    return rayStart;
}

glm::vec3 Ray::getDirection()
{
    return rayPoint - rayStart;
}

void Ray::setColor(ColorDbl c)
{
    color = c;
}

ColorDbl Ray::getColor()
{
    return color;
}


