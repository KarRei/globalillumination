#ifndef SURFACE_H
#define SURFACE_H

#include <ColorDbl.h>

class Surface
{
    public:
        Surface();
        Surface(ColorDbl);
        virtual ~Surface();

        ColorDbl getColor ();

    protected:

    private:
        ColorDbl color;
        //lambertian
        //specular
};

#endif // SURFACE_H
