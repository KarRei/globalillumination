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
    glm::vec3 normal = hit_point - position;

    Ray temp;

    const float PI = 3.1415926535897932384626433832795;
    float rand1 = (float)rand()/(float)RAND_MAX;
    float rand2 = (float)rand()/(float)RAND_MAX;

    float azimuth = PI * rand1 * 2.0f;
    float elevation = acos(sqrt(rand2));

    glm::vec3 tangent = glm::normalize(glm::cross(normal, normal + glm::vec3(1.f)));
    glm::vec3 reflected_dir = normal;

    reflected_dir = glm::normalize(glm::rotate(reflected_dir, elevation, tangent));
    reflected_dir = glm::normalize(glm::rotate(reflected_dir, azimuth, normal));

    temp = Ray(hit_point, reflected_dir);
    return temp;
}

