#ifndef DIRECTION_H
#define DIRECTION_H

#include "../glm/glm/glm.hpp"
#include <Vertex.h>

class Direction
{
    public:
        Direction();
        Direction(Vertex);
        virtual ~Direction();

    protected:

    private:
        Vertex direction;
};

#endif // DIRECTION_H
