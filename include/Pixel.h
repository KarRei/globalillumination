#ifndef PIXEL_H
#define PIXEL_H

#include <pixel.h>
#include <ColorDbl.h>


class Pixel
{
    public:
        Pixel();
        Pixel(ColorDbl);
        virtual ~Pixel();

    protected:

    private:
        ColorDbl color;
};

#endif // PIXEL_H
