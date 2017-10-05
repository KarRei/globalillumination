#include "Pixel.h"

Pixel::Pixel()
{
    //color should be set by the reference isch
    color = glm::vec3(0.0f);
}

Pixel::Pixel(ColorDbl a)
{
    //color should be set by the reference isch
    color = a;
}

Pixel::~Pixel()
{
    //dtor
}
