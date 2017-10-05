#ifndef RAY_H
#define RAY_H

#include "../glm/glm/glm.hpp"

#include <Vertex.h>
#include <ColorDbl.h>

class Ray
{
    public:
        Ray();
        Ray(Vertex s, Vertex e);
        virtual ~Ray();

        glm::vec3 getStart();

    protected:

    private:
        Vertex rayStart, rayEnd;
        ColorDbl color;

        //referera till triangle
};

#endif // RAY_H
