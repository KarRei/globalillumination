#ifndef PIXEL_H
#define PIXEL_H

#include <pixel.h>
#include <ColorDbl.h>
#include <Ray.h>


class Pixel
{
    public:
        Pixel();
        Pixel(ColorDbl);
        virtual ~Pixel();

    protected:

    private:
        ColorDbl color;
        //reference to a ray (the ray that goes through it)
        //Ray& refRay;
};

#endif // PIXEL_H
