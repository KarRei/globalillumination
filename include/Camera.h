#ifndef CAMERA_H
#define CAMERA_H

//#include "Vertex.h"
#include "Pixel.h"
#include "Scene.h"
#include "Direction.h"
#include "../glm/glm/glm.hpp"
#include <array>
#include <vector>
#include <Ray.h>

//Se vilka vi behöver!!
#include <stdlib.h>
#include <stdio.h>
//#include <math.h>
#include <iomanip>
#include <iostream>


class Camera
{
    public:
        Camera();
        virtual ~Camera();

        void render(Scene&);
        void createImage(const string filename = "image.ppm");

        //void writeToFile(const string filename, glm::vec3 img[1000][1000]);

    protected:

    private:
        glm::vec3 eye;
        //When you allocate large arrays in the static storage, you can make much larger arrays. Otherwise memory overflow.
        // https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
        Pixel **imagePlane = new Pixel*[1000];

        const int max_val = 1000;

};

#endif // CAMERA_H
