#ifndef SURFACE_H
#define SURFACE_H

#include <ColorDbl.h>

class Surface
{
    public:
        Surface();
        Surface(ColorDbl c, float brdf);
        virtual ~Surface();

        ColorDbl getColor ();
        float getBRDF();

    protected:

    private:
        ColorDbl color;
        float BRDF;
        //glm::vec3 emission;

        //lambertian
        //specular
};

#endif // SURFACE_H
