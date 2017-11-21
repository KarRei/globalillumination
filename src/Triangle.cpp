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
    if (surface.getModel() == 1)
        temp = Ray(hit_point, glm::reflect(r.getDirection(), normal));

    //Reflection for lambertian surfaces
    else if (surface.getModel() == 0)
    {
        /*
        float random1 = (float) rand();
        float random2 = (float) rand();

        float angle1 = acos(sqrt(random1));
        float angle2 = 2.f * 3.14 * random2;

        //You can find tangent by calculating the cross-product of the normal and an arbitrary vector that isn't parallel to the normal
        glm::vec3 tangent = glm::normalize(glm::cross(normal, normal + glm::vec3(1.f)));

        glm::vec3 new_direction = normal;

        new_direction = glm::normalize(glm::rotate(new_direction, angle1, tangent));
        new_direction = glm::normalize(glm::rotate(new_direction, angle2, normal));

        temp = Ray(hit_point, new_direction);*/

        //Hemisphere

        //glm::vec3 perfectRefl = glm::normalize( r.getDirection() ) - glm::vec3(1, 1, 1) * glm::normalize(glm::dot(r.getDirection(), normal * normal));
        glm::vec3 new_dir; // = normal;

        do {

            float random_x = (float)rand()/(float)RAND_MAX*2 - 1;
            float random_y = (float)rand()/(float)RAND_MAX*2 - 1;
            float random_z = (float)rand()/(float)RAND_MAX*2 - 1;

            new_dir = glm::normalize(glm::vec3(random_x, random_y, random_z));

        } while ( glm::dot(normal, new_dir) < 0 ); //continue until new direction is out from the hemisphere

        temp = Ray(hit_point, new_dir);
/*
        const float PI = 3.1415926535897932384626433832795;
        float rand1 = (float)rand()/(float)RAND_MAX;
        float rand2 = (float)rand()/(float)RAND_MAX;
        float phi = acos ( sqrt (rand1 ) );
        float theta = 2.f * PI * rand2;

        glm::vec3 tangent = glm::normalize(glm::cross(normal, normal + glm::vec3(1.f)));
        glm::vec3 reflected_dir = normal;

        reflected_dir = glm::normalize(glm::rotate(reflected_dir, phi, tangent));
        reflected_dir = glm::normalize(glm::rotate(reflected_dir, theta, normal));

        temp = Ray(hit_point, reflected_dir);*/

    }
    return temp;
}






















