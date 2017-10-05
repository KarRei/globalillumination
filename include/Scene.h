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

        Triangle rayIntersection(Ray);

    protected:

    private:
        vector<Triangle> triangles;
};

#endif // SCENE_H
