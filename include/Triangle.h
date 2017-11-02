#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <array>
#include <Vertex.h>
#include <Direction.h>
#include <ColorDbl.h>
#include <Surface.h>
#include <Ray.h>
#include "../glm/glm/glm.hpp"

using namespace std;

class Triangle
{
    public:
        Triangle();
        Triangle(glm::vec3, glm::vec3, glm::vec3, Surface);
        virtual ~Triangle();

        glm::vec3 getPoint(int p);

        glm::vec3 getNormal();

        ColorDbl getColor();
        float getBRDF();

        Ray getReflectedRay(Ray &r);

    protected:

    private:
        glm::vec3 pointPos1;
        glm::vec3 pointPos2;
        glm::vec3 pointPos3;
        glm::vec3 normal;
        Surface surface;
};

#endif // TRIANGLE_H
