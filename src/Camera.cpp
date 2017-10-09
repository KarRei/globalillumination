#include "Camera.h"

Camera::Camera()
: eye(-2.0f, 0.0f, 0.0f)
{ }

Camera::~Camera()
{
    //dtor
}


void Camera::render(Scene &scene) {
    //loop through the pixels
    //set pixel color from ray

    for (int z = 0; z < max_val; z++) {
        for (int y = 0; y < max_val; y++) {

            glm::vec3 imagePlanePosition(0, y*0.002 - 0.999, z*0.002 - 0.999);

            //crete a ray from the eye to current pixel
            Ray r(eye, imagePlanePosition);

            // Launch the ray into the scene. The function will take the reference to the ray and set it's color.
            scene.rayIntersection(r);

            //Create a new pixel with the color from the ray and store it in imagePlane
            imagePlane[z][y] = Pixel(r.getColor());
        }
    }

    //delete ray(not nec)
}

void Camera::createImage() {
    //loop through imgPlane and fill with Pixel-objects (call pixel constr with ray-reference)
    //Crete image file
    for (int z = 0; z < max_val; z++) {
        for (int y = 0; y < max_val; y++) {
                //loop through all color channels RGB and find largest intensity value i_max
                //Extract ColorDbl of each pixel and multiply with 255.99/imax

        }
    }



}
