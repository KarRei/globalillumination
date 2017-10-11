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
    Camera camera;
    cout << "3" << endl;
    camera.render(scene);
cout << "4" << endl;


    return 0;

}

