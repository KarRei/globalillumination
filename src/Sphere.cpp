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
    glm::vec3 normal = position - hit_point;

    glm::vec3 reflected_dir;
    // specular reflection
    if (surface.getModel() == 1)
        reflected_dir = glm::reflect(r.getDirection(), normal);

    else if (surface.getModel() == 0)
    {
        float random1 = (float) rand();
        float random2 = (float) rand();

        float angle1 = acos(sqrt(random1));
        float angle2 = 2.f * 3.14 * random2;

        //You can find tangent by calculating the cross-product of the normal and an arbitrary vector that isn't parallel to the normal
        glm::vec3 tangent = glm::normalize(glm::cross(normal, normal + glm::vec3(1.f)));

        glm::vec3 reflected_dir = normal;

        reflected_dir = glm::normalize(glm::rotate(reflected_dir, angle1, tangent));
        reflected_dir = glm::normalize(glm::rotate(reflected_dir, angle2, normal));
    }

    Ray temp(hit_point, reflected_dir);
    return temp;
}

