#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <array>
#include <Vertex.h>
#include <Direction.h>
#include <ColorDbl.h>
#include <Surface.h>
#include "../glm/glm/glm.hpp"

using namespace std;

class Triangle
{
    public:
        Triangle();
        Triangle(glm::vec3, glm::vec3, glm::vec3, Surface);
        virtual ~Triangle();

        glm::vec3 getPoint(int p);

        Direction getNormal();

        ColorDbl getColor();

    protected:

    private:
        glm::vec3 pointPos1;
        glm::vec3 pointPos2;
        glm::vec3 pointPos3;
        //Surface surface;
        Direction normal;
        ColorDbl color;
};

#endif // TRIANGLE_H
