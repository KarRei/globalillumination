#ifndef PIXEL_H
#define PIXEL_H

#include <pixel.h>
#include <ColorDbl.h>
#include <Ray.h>


class Pixel
{
    public:
        Pixel();
        Pixel(glm::vec3);
        virtual ~Pixel();

        glm::vec3 getColor();
        void setColor(glm::vec3);

    protected:

    private:
        glm::vec3 color;
        //reference to a ray (the ray that goes through it)
        //Ray& refRay;
};

#endif // PIXEL_H
