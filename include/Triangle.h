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
        Triangle(Vertex a, Vertex b, Vertex c, Surface s);
        virtual ~Triangle();

        glm::vec3 getPoint(int p);

        Direction getNormal();

        ColorDbl getColor();

    protected:

    private:
        Vertex pointPos1;
        Vertex pointPos2;
        Vertex pointPos3;
        //Surface surface;
        Direction normal;
        ColorDbl color;
};

#endif // TRIANGLE_H
