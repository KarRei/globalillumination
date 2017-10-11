#ifndef CAMERA_H
#define CAMERA_H

#include "Vertex.h"
#include "Pixel.h"
#include "Scene.h"
#include <Direction.h>
#include "../glm/glm/glm.hpp"

//Se vilka vi behöver!!
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>


class Camera
{
    public:
        Camera();
        virtual ~Camera();

        void render(Scene&);
        void createImage();

        void writeToFile(const string filename, glm::vec3 img[1000][1000]);

    protected:

    private:
        glm::vec3 eye;
        //Pixel imagePlane[1000][1000];

        const int max_val = 1000;

};

#endif // CAMERA_H
