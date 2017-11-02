#ifndef RAY_H
#define RAY_H

#include "../glm/glm/glm.hpp"

#include <Vertex.h>
#include <ColorDbl.h>


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

};

#endif // RAY_H
