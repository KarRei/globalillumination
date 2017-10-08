#ifndef RAY_H
#define RAY_H

#include "../glm/glm/glm.hpp"

#include <Vertex.h>
#include <ColorDbl.h>
#include <Triangle.h>

class Ray
{
    public:
        Ray();
        Ray(glm::vec3 s, glm::vec3 e);
        virtual ~Ray();

        glm::vec3 getStart();
        glm::vec3 getDirection();
        void setColor(ColorDbl c);
        ColorDbl getColor();

    protected:

    private:
        glm::vec3 rayStart, rayPoint;
        ColorDbl color;
        //reference to triange (the triangle that the ray hits, if any)
        //Triangle& refTri;
};

#endif // RAY_H
