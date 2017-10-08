#include "Camera.h"

Camera::Camera()
: eye(-2.0f, 0.0f, 0.0f)
{
    Render();
}

Camera::~Camera()
{
    //dtor
}


void Camera::Render() {
    //loop through the pixels
    //set pixel color from ray

    for (int z = 0; z < max_val; z++) {
        for (int y = 0; y < max_val; y++) {

            glm::vec3 p(0, y*0.002 - 0.999, z*0.002 - 0.999);
            //crete a ray from the eye to current pixel
            Ray r(eye, p);

            Scene::rayIntersection(r);

            imagePlane[z][y] = Pixel(r.getColor());
        }
    }
        //save to current pixel


    //delete ray(not nec)
}

void Camera::CreateImage() {
    //loop through imgPlane and fill with Pixel-objects (call pixel constr with ray-reference)
    //Crete image file
    for (int z = 0; z < max_val; z++) {
        for (int y = 0; y < max_val; y++) {
                //loop through all color channels RGB and find largest intensity value i_max
                //Extract ColorDbl of each pixel and multiply with 255.99/imax

        }
    }



}
