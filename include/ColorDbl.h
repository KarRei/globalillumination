#ifndef COLORDBL_H
#define COLORDBL_H

#include "../glm/glm/glm.hpp"

class ColorDbl
{
    public:
        ColorDbl();
        ColorDbl(glm::vec3);
        virtual ~ColorDbl();

        glm::vec3 getColorVec();

        ColorDbl operator*(const float& f)
        {
            ColorDbl c;
            c.color = this->color * f;
            return c;
        }

    protected:

    private:
        glm::vec3 color;

};

#endif // COLORDBL_H
