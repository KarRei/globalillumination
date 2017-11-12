#include "Sphere.h"
Sphere::Sphere()
{
        position = glm::vec3(0.f);
        radius = 0.f;
}

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

Surface Sphere::getSurface()
{
    return surface;
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

glm::vec3 Sphere::getNormal(glm::vec3 hit_point)
{
    return glm::normalize(position - hit_point);
}

Ray Sphere::getReflectedRay( Ray &r, glm::vec3 hit_point )
{
    glm::vec3 normal = position - r.getDirection();
    Ray temp(r.getDirection(), glm::reflect(r.getDirection(), normal));
    return temp;
}

