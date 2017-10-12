#include "Triangle.h"

Triangle::Triangle()
{}

Triangle::Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c, Surface s) // should it be a reference to the surface?
{
    pointPos1 = a;
    pointPos2 = b;
    pointPos3 = c;

    color = s.getColor();

    //calculate the normal
    normal = getNormal();
}

Triangle::~Triangle()
{
    //dtor
}

Direction Triangle::getNormal()
{
    glm::vec3 edge1 = pointPos2 - pointPos1;
    glm::vec3 edge2 = pointPos3 - pointPos1;

    Direction norm(glm::normalize(glm::cross(edge1, edge2)));
    return norm;
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
    return color;
}


