#ifndef LIGHT_H
#define LIGHT_H

#include "../glm/glm/glm.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Light
{
    public:
        Light();
        virtual ~Light();

        glm::vec3 getRandomPoint();

    protected:

    private:
        glm::vec3 p1, p2, p3, p4;
};

#endif // LIGHT_H
