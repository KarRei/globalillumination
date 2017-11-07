#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <Triangle.h>
#include <Ray.h>
#include <Direction.h>
#include <Sphere.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Scene
{
    public:
        Scene();
        //virtual ~Scene();
        void createRoom();

        Ray getLastRay();
        void rayIntersection(Ray r);
        bool tryIntersectionTriangle(glm::vec3 D, glm::vec3 start, Triangle& t, float& d);
        bool tryIntersectionSphere(glm::vec3 direction, glm::vec3 start, Sphere& sph, float& distance);

    protected:

    private:
        vector<Triangle> triangles;
        vector<Sphere> spheres;
        vector<Ray> rays; // in order of the way the ray travels through the scene for each pixel
};

#endif // SCENE_H
