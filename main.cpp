#include <iostream>
#include "glm/glm/glm.hpp"

#include "Scene.h"
#include "Camera.h"

using namespace std;

int main() {

    //Create scene
    Scene scene;

    Camera camera;
    camera.render(scene);

    return 0;

}

