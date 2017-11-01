#ifndef SPHERE_H
#define SPHERE_H

#include <Surface.h>
#include <ColorDbl.h>

class Sphere
{
    public:
        Sphere(glm::vec3 pos, float rad, Surface s );
        virtual ~Sphere();

        ColorDbl getColor();
        float getRadius();
        glm::vec3 getPosition();

    protected:

    private:
        glm::vec3 position;
        float radius;
        ColorDbl color;
};

#endif // SPHERE_H
