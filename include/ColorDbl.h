#ifndef COLORDBL_H
#define COLORDBL_H

#include "../glm/glm/glm.hpp"

class ColorDbl
{
    public:
        ColorDbl();
        ColorDbl(glm::vec3);
        virtual ~ColorDbl();

    protected:

    private:
        glm::vec3 color;

};

#endif // COLORDBL_H
