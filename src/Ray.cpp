#include "Ray.h"

Ray::Ray()
: rayStart(glm::vec3(0.0f)), rayEnd(glm::vec3(0.0f))
{ }

Ray::Ray(Vertex s, Vertex e)
{
    rayStart = s;
    rayEnd = e;
}

Ray::~Ray()
{
    //dtor
}

glm::vec3 Ray::getStart()
{
    return rayStart.getVec3();
}

