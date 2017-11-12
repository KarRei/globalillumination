#include "Triangle.h"

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

Ray Triangle::getReflectedRay( Ray &r )
{
    //Reflection for specular
    Ray temp(r.getDirection(), glm::reflect(r.getDirection(), normal));


    //Reflection for Lambertian surfaces




    //set importance
    //temp.setImportance(surface.getBRDF() * r.getImportance());

    return temp;
}


