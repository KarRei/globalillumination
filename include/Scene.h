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
#include <math.h>
#include <list>
//#include <../glm/glm/gtx/string_cast.hpp>
//#include <../glm/glm/gtx/component_wise.hpp>
#include <../glm/glm/gtx/vector_angle.hpp>


using namespace std;

const int MAX_ITERATIONS = 3;

struct TriangleIntersection {
    Triangle triangle;
    glm::vec3 point;
};

struct SphereIntersection {
    Sphere sphere;
    glm::vec3 point;
};

class Scene
{
    public:
        Scene();
        void createRoom();

        glm::vec3 rayIntersection(Ray &r, int nr_iterations = 0);
        list<TriangleIntersection> firstIntersectedTriangle(Ray r);
        list<SphereIntersection> firstIntersectedSphere(Ray r);
        bool tryIntersectionTriangle(glm::vec3 D, glm::vec3 start, Triangle& t, glm::vec3& iPoint);
        bool tryIntersectionSphere(glm::vec3 direction, glm::vec3 start, Sphere& sph, glm::vec3& iPoint);
        glm::vec3 castShadowRay(Ray& rayIncoming, glm::vec3 normal, glm::vec3 hitPoint);

    protected:

    private:
        vector<Triangle> triangles;
        vector<Sphere> spheres;
        vector<Triangle> intersectedTri;
        vector<Sphere> intersectedSph;
        Light lightSource;

};

#endif // SCENE_H
