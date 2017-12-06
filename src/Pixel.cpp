#include "Pixel.h"

Pixel::Pixel()
: color(glm::vec3(0.0f, 0.0f, 0.0f))
{
}

Pixel::Pixel(glm::vec3 c)
{
    //color should be set by the reference isch
    color = c;
}

Pixel::~Pixel()
{
    //dtor
}

glm::vec3 Pixel::getColor() {
    return color;
}

void Pixel::setColor(glm::vec3 c) {
    color = c;
}
