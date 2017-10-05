#include "Vertex.h"


Vertex::Vertex()
{
    position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
}

Vertex::Vertex(glm::vec3 a)
{
    position = glm::vec4(a, 1.0f);
}

Vertex::~Vertex()
{

}

glm::vec3 Vertex::getVec3()
{
    return glm::vec3(this->position.x, this->position.y, this->position.z);
}
