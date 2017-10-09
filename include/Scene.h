#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <Triangle.h>
#include <Ray.h>
#include <Direction.h>

using namespace std;

class Scene
{
    public:
        Scene();
        virtual ~Scene();
        void createRoom();

        void rayIntersection(Ray& r);
        bool tryIntersection(glm::vec3 D, glm::vec3 start, Triangle* t, float& d);

    protected:

    private:
        vector<Triangle> triangles;
};

#endif // SCENE_H
