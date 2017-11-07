#include "Sphere.h"

Sphere::Sphere(glm::vec3 pos, float rad, Surface s )
{
        position = pos;
        radius = rad;
        surface = s;
}

Sphere::~Sphere()
{
    //dtor
}

float Sphere::getBRDF()
{
    return surface.getBRDF();
}

ColorDbl Sphere::getColor()
{
    return surface.getColor();
}

float Sphere::getRadius()
{
    return radius;
}

glm::vec3 Sphere::getPosition()
{
    return position;
}

Ray Sphere::getReflectedRay( Ray &r )
{
    glm::vec3 normal = position - r.getDirection();
    Ray temp(r.getDirection(), glm::reflect(r.getDirection(), normal));
    return temp;
}

