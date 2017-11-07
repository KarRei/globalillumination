#ifndef SPHERE_H
#define SPHERE_H

#include <Surface.h>
#include <ColorDbl.h>
#include <Ray.h>

class Sphere
{
    public:
        Sphere(glm::vec3 pos, float rad, Surface s );
        virtual ~Sphere();

        ColorDbl getColor();
        float getRadius();
        glm::vec3 getPosition();
        float getBRDF();
        Ray getReflectedRay(Ray &r);

    protected:

    private:
        glm::vec3 position;
        float radius;
        Surface surface;
};

#endif // SPHERE_H
