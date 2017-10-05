#ifndef VERTEX_H
#define VERTEX_H

#include "../glm/glm/glm.hpp"

class Vertex
{
    public:
        Vertex();
        Vertex(glm::vec3);
        virtual ~Vertex();

        glm::vec3 getVec3();

    protected:

    private:
        //Homogenous coordinates
        glm::vec4 position;

};

#endif // VERTEX_H
