#include "Pixel.h"

Pixel::Pixel()
: color(glm::vec3(0.0f, 0.0f, 0.0f))
{
}

Pixel::Pixel(ColorDbl c)
{
    //color should be set by the reference isch
    color = c;
}

Pixel::~Pixel()
{
    //dtor
}
