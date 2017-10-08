#include "Triangle.h"

Triangle::Triangle()
: pointPos1(), pointPos2(), pointPos3(), color(), normal(glm::vec3(0.0f))
{}

Triangle::Triangle(Vertex a, Vertex b, Vertex c, Surface s) // should it be a reference to the surface?
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
    glm::vec3 edge1 = pointPos2.getVec3() - pointPos1.getVec3();
    glm::vec3 edge2 = pointPos3.getVec3() - pointPos1.getVec3();

    Direction norm(glm::normalize(glm::cross(edge1, edge2)));
    return norm;
}

glm::vec3 Triangle::getPoint(int p)
{
    if(p == 1)
        return pointPos1.getVec3();

    if(p == 2)
        return pointPos2.getVec3();

    return pointPos3.getVec3();
}


ColorDbl Triangle::getColor()
{
    return color;
}


