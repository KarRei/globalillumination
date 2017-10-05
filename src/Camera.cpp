#include "Camera.h"

Camera::Camera()
: eye(glm::vec3(-2.0f, 0.0f, 0.0f))
{
}

Camera::~Camera()
{
    //dtor
}


void Camera::Render() {
    //loop through the pixels
    //set pixel color from ray

    //delete ray(not nec)
}

void Camera::CreateImage() {
    const int max_val = 1000;

    //loop through the pixels
    for (int z = 0; z < max_val; z++) {
        for (int y = 0; y < max_val; y++) {
            //loop through all color channels RGB and find largest intensity value i_max
            Vertex p(glm::vec3(0, y*0.002 - 0.999, z*0.002 - 0.999));
            //Extract ColorDbl of each pixel and multiply with 255.99/imax
            glm::vec3 rayDir(p.getVec3() - eye.getVec3());
            //save to
        }
    }



}
