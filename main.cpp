#include <iostream>
#include "glm/glm/glm.hpp"

#include "Scene.h"
#include "Camera.h"

using namespace std;

int main() {

    //Create scene
    cout << "1" << endl;
    Scene scene;
    cout << "2" << endl;
    Camera cam;
    cout << "3" << endl;
    cam.render(scene);
    cout << "4" << endl;
    cam.createImage();
    cout << "5" << endl;


    return 0;

}

