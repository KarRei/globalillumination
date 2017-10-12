#include "Pixel.h"

Pixel::Pixel()
: color(ColorDbl(glm::vec3(0.0f, 0.0f, 0.0f)))
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

glm::vec3 Pixel::getColor() {
    return color.getColorVec();
}

void Pixel::setColor(ColorDbl c) {
    color = c;
}
