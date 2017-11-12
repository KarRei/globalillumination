#ifndef SURFACE_H
#define SURFACE_H

#include <ColorDbl.h>

//int LAMBERTIAN = 0;
//int SPECULAR = 1;
//int LIGHT = 2;

class Surface
{
    public:
        Surface();
        Surface(ColorDbl c, int model = 0);
        virtual ~Surface();

        ColorDbl getColor ();
        glm::vec3 getIntensity();
        int getModel();

    protected:

    private:
        ColorDbl color;
        int model;
        glm::vec3 intensity;

        //lambertian
        //specular
};

#endif // SURFACE_H
