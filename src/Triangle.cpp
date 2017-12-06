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
    //Reflection for specular surfaces
    //if (surface.getModel() == 1)
        //temp = Ray(hit_point, glm::reflect(r.getDirection(), normal));

    //Reflection for lambertian surfaces
    //else if (surface.getModel() == 0)
    //{

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






















