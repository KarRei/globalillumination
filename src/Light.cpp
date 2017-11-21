#include "Light.h"

Light::Light()
{
    p1 = glm::vec3(4.0f, 1.0f, 4.99f);
    p2 = glm::vec3(4.0f, -1.0f, 4.99f);
    p3 = glm::vec3(6.0f, -1.0f, 4.99f);
    p4 = glm::vec3(6.0f, 1.0f, 4.99f);

    surface = Surface(ColorDbl(glm::vec3(1.0f, 1.0f, 1.0f)), 2);
}

Light::~Light()
{
    //dtor
}

glm::vec3 Light::getNormal()
{
    return glm::vec3(0.0f, -1.0f, 0.0f);
}

Surface Light::getSurface()
{
    return surface;
}

float Light::getArea()
{
    return (glm::abs(p3.x - p1.x) * glm::abs(p3.y - p1.y));
}

glm::vec3 Light::getRandomPoint()
{
    float random = ((float) rand()) / (float) RAND_MAX;

    float randX = random * (6.0f - 4.0f) + 4.0f;
    float randY = 2 * random - 1;

    return glm::vec3(randX, randY, 4.90f);
}
