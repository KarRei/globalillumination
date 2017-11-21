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
    return glm::normalize(hit_point - position);
}

Ray Sphere::getReflectedRay( Ray &r, glm::vec3 hit_point )
{
    glm::vec3 reflected_dir;
    glm::vec3 normal = hit_point - position;

    // specular reflection
    reflected_dir = glm::reflect(r.getDirection(), normal);

    Ray temp(hit_point, reflected_dir);
    return temp;
}

