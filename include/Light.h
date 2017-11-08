#ifndef LIGHT_H
#define LIGHT_H


class Light
{
    public:
        Light();
        virtual ~Light();

    protected:

    private:
        glm::vec3 p1, p2, p3, p4;
        float intensity;
};

#endif // LIGHT_H
