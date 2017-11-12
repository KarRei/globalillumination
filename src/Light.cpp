#include "Light.h"

Light::Light()
{
    p1 = glm::vec3(4.0f, 1.0f, 4.99f);
    p2 = glm::vec3(4.0f, -1.0f, 4.99f);
    p3 = glm::vec3(6.0f, -1.0f, 4.99f);
    p4 = glm::vec3(6.0f, 1.0f, 4.99f);
}

Light::~Light()
{
    //dtor
}

glm::vec3 Light::getRandomPoint()
{

    float random = ((float) rand()) / (float) RAND_MAX;

    float diffX = 6.0f - 4.0f;
    float rX = random * diffX;

    float diffY = 1.0f + 1.0f;
    float rY = random * diffY;


    float randX = 4.0f + rX;
    float randY = -1.0f + rY;

    return glm::vec3(randX, randY, 4.99f);

   /*float randX = 4.0f + rand() % (6.0f - 4.0f);
   float randY = -1.0f + rand() % (1.0f + 1.0f);*/

}
