#ifndef CAMERA_H
#define CAMERA_H

#include "Vertex.h"
#include "Pixel.h"
#include <Direction.h>
#include "../glm/glm/glm.hpp"


class Camera
{
    public:
        Camera();
        virtual ~Camera();

        void Render();
        void CreateImage();

    protected:

    private:
        Vertex eye;
        Pixel imagePlane[1000][1000];

};

#endif // CAMERA_H
