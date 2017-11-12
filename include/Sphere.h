#ifndef SPHERE_H
#define SPHERE_H

#include <Surface.h>
#include <ColorDbl.h>
#include <Ray.h>

class Sphere
{
    public:
        Sphere();
        Sphere(glm::vec3 pos, float rad, Surface s );
        virtual ~Sphere();

        Surface getSurface();
        ColorDbl getColor();
        float getRadius();
        glm::vec3 getPosition();
        Ray getReflectedRay(Ray &r);
        glm::vec3 getNormal(glm::vec3 hit_point);

    protected:

    private:
        glm::vec3 position;
        float radius;
        Surface surface;
};

#endif // SPHERE_H
