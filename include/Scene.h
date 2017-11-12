#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <Triangle.h>
#include <Ray.h>
#include <Direction.h>
#include <Sphere.h>
#include <Light.h>
#include <iostream>
#include <string>
#include <iomanip>
//#include <../glm/glm/gtx/string_cast.hpp>
//#include <../glm/glm/gtx/component_wise.hpp>

using namespace std;

const int MAX_ITERATIONS = 3;
//int nr_iterations = 0;

class Scene
{
    public:
        Scene();
        //virtual ~Scene();
        void createRoom();

        glm::vec3 rayIntersection(Ray &r, int nr_iterations = 0);
        Triangle firstIntersectedTriangle(Ray& r, glm::vec3& hPoint);
        Sphere firstIntersectedSphere(Ray& r, glm::vec3& hPoint);
        bool tryIntersectionTriangle(glm::vec3 D, glm::vec3 start, Triangle& t, float &d, glm::vec3& iPoint);
        bool tryIntersectionSphere(glm::vec3 direction, glm::vec3 start, Sphere& sph, float &distance, glm::vec3& iPoint);
        glm::vec3 castShadowRay(Ray& rayIncoming, glm::vec3 normal, glm::vec3 hitPoint);

    protected:

    private:
        vector<Triangle> triangles;
        vector<Sphere> spheres;
        //vector<Ray> rays; // in order of the way the ray travels through the scene for each pixel
        vector<Triangle> intersectedTri;
        vector<Sphere> intersectedSph;
        Light lightSource;

};

#endif // SCENE_H
