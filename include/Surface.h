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
        int getModel();

    protected:

    private:
        ColorDbl color;
        //float BRDF;
        int model;

        //glm::vec3 emission;

        //lambertian
        //specular
};

#endif // SURFACE_H
