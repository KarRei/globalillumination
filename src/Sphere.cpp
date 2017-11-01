#include "Sphere.h"

Sphere::Sphere(glm::vec3 pos, float rad, Surface s )
{
        position = pos;
        radius = rad;
        color = s.getColor();
}

Sphere::~Sphere()
{
    //dtor
}

ColorDbl Sphere::getColor()
{
    return color;
}

float Sphere::getRadius()
{
    return radius;
}

glm::vec3 Sphere::getPosition()
{
    return position;
}

/*
glm::vec3 Sphere::getNormal ()
{
    return color;
}*/

