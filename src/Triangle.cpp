#include "Triangle.h"
#define M_PI

Triangle::Triangle()
{}

Triangle::Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c, Surface s) // should it be a reference to the surface?
{
    pointPos1 = a;
    pointPos2 = b;
    pointPos3 = c;

    surface = s;

    //calculate the normal
    normal = getNormal();
}

Triangle::~Triangle()
{
    //dtor
}

glm::vec3 Triangle::getNormal()
{
    glm::vec3 edge1 = pointPos2 - pointPos1;
    glm::vec3 edge2 = pointPos3 - pointPos1;

    return (glm::normalize(glm::cross(edge1, edge2)));
}

glm::vec3 Triangle::getPoint(int p)
{
    if(p == 1)
        return pointPos1;

    if(p == 2)
        return pointPos2;

    return pointPos3;
}


ColorDbl Triangle::getColor()
{
    return surface.getColor();
}

Surface Triangle::getSurface()
{
    return surface;
}

Ray Triangle::getReflectedRay( Ray &r, glm::vec3 hit_point )
{
    Ray temp;
    //Reflection for specular
    if (surface.getModel() == 1)
        temp = Ray(hit_point, glm::reflect(r.getDirection(), normal));

    //Reflection for lambertian
    else if (surface.getModel() == 0)
    {
        float random1 = (float) rand();
        float random2 = (float) rand();

        float angle1 = acos(sqrt(random1));
        float angle2 = 2.f * 3.14 * random2;

        //You can find tangent by calculating the cross-product of the normal and an arbitrary vector that isn't parallel to the normal
        glm::vec3 tangent = glm::normalize(glm::cross(normal, normal + glm::vec3(1.f)));

        glm::vec3 new_direction = normal;

        new_direction = glm::normalize(glm::rotate(new_direction, angle1, tangent));
        new_direction = glm::normalize(glm::rotate(new_direction, angle2, normal));

        temp = Ray(hit_point, new_direction);

    }

    return temp;
}






















