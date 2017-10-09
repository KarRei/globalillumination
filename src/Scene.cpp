#include "Scene.h"

Scene::Scene()
{
    createRoom();
}

Scene::~Scene()
{

}

void Scene::createRoom(){

    //Defining points in room
    glm::vec3 aTop(13.0f, 0.0f, 5.0f), aBottom(13.0f, 0.0f, -5.0f);
    glm::vec3 bTop(10.0f, 6.0f, 5.0f), bBottom(10.0f, 6.0f, -5.0f);
    glm::vec3 cTop(10.0f, -6.0f, 5.0f), cBottom(10.0f, -6.0f, -5.0f);
    glm::vec3 dTop(0.0f, 6.0f, 5.0f), dBottom(0.0f, 6.0f, -5.0f);
    glm::vec3 eTop(0.0f, -6.0f, 5.0f), eBottom(0.0f, -6.0f, -5.0f);
    glm::vec3 fTop(-3.0f, 0.0f, 5.0f), fBottom(-3.0f, 0.0f, -5.0f);

    //Create surfaces
    Surface wall1(ColorDbl(glm::vec3(1.0f, 0.0f, 0.0f))); //red
    Surface wall2(ColorDbl(glm::vec3(0.0f, 0.0f, 1.0f))); //blur
    Surface wall3(ColorDbl(glm::vec3(0.0f, 1.0f, 0.0f))); //green
    Surface wall4(ColorDbl(glm::vec3(1.0f, 1.0f, 0.0f))); //yellow
    Surface wall5(ColorDbl(glm::vec3(1.0f, 0.0f, 1.0f))); //purple
    Surface wall6(ColorDbl(glm::vec3(1.0f, 0.6f, 0.0f))); //orange
    Surface bottomTop(ColorDbl(glm::vec3(0.0f, 0.0f, 0.0f))); //white

    //Create Triangles 20 with normal in
    //Walls
    Triangle t1_a(bBottom, aBottom, aTop, wall1);
    Triangle t1_b(bBottom, aTop, bTop, wall1);
    Triangle t2_a(aBottom, cBottom, cTop, wall2);
    Triangle t2_b(aBottom, cTop, aTop, wall2);
    Triangle t3_a(dBottom, bBottom, bTop, wall3);
    Triangle t3_b(dBottom, bTop, dTop, wall3);
    Triangle t4_a(eBottom, eTop, cBottom, wall4);
    Triangle t4_b(eTop, cTop, cBottom, wall4);
    Triangle t5_a(fBottom, dBottom, dTop, wall5);
    Triangle t5_b(fBottom, dTop, fTop, wall5);
    Triangle t6_a(eBottom, fBottom, fTop, wall6);
    Triangle t6_b(eBottom, fBottom, eTop, wall6);
    //Floor
    Triangle tf_a(fBottom, eBottom, dBottom, bottomTop);
    Triangle tf_b(eBottom, cBottom, dBottom, bottomTop);
    Triangle tf_c(dBottom, cBottom, bBottom, bottomTop);
    Triangle tf_d(cBottom, aBottom, bBottom, bottomTop);
    //Roof
    Triangle tr_a(fTop, dTop, eTop, bottomTop);
    Triangle tr_b(eTop, dTop, cTop, bottomTop);
    Triangle tr_c(dTop, bTop, cTop, bottomTop);
    Triangle tr_d(cTop, bTop, aTop, bottomTop);

    //Add triangles to the mesh triangles
    triangles.push_back(t1_a);
    triangles.push_back(t1_b);
    triangles.push_back(t2_a);
    triangles.push_back(t2_b);
    triangles.push_back(t3_a);
    triangles.push_back(t3_b);
    triangles.push_back(t4_a);
    triangles.push_back(t4_b);
    triangles.push_back(t5_a);
    triangles.push_back(t5_b);
    triangles.push_back(t6_a);
    triangles.push_back(t6_b);
    triangles.push_back(tf_a);
    triangles.push_back(tf_b);
    triangles.push_back(tf_c);
    triangles.push_back(tf_d);
    triangles.push_back(tr_a);
    triangles.push_back(tr_b);
    triangles.push_back(tr_c);
    triangles.push_back(tr_d);

    //Objects

    //Light


}

void Scene::rayIntersection(Ray& r)
{
    //snygga till nödlösningen!!

    //Loop through all triangles in scene
    //Loop the current triangle
    Triangle* temp;
    float distance = 1000.0f;

    for(vector<Triangle>::iterator it = triangles.begin(); it != triangles.end(); it++)
    {
        //If true, intersection!

        //Passing it just passes an itterator object, it* passes the underlying object,
        //&(*it) passes the address to that underlying object
        if (tryIntersection(r.getDirection(), r.getStart(), &(*it), distance))
            temp = &(*it);
    }

    r.setColor(temp->getColor());

}

bool Scene::tryIntersection(glm::vec3 D, glm::vec3 start, Triangle* tri, float& d)
{
    //Möller Trumbore Algorithm
    float a, f, v, u;
    glm::vec3 e1, e2, T, P, Q;
    e1 = tri->getPoint(2) - tri->getPoint(1);
    e2 = tri->getPoint(3) - tri->getPoint(1);

    T = start - tri->getPoint(1);
    P = glm::normalize(glm::cross(D, e2));
    Q = glm::normalize(glm::cross(T, e1));

    a = glm::dot(P, e1);

    if (a == 0.0) {
        return false;
    }
    f = 1/a;
    u = f * (glm::dot(P, T));
    v = f * (glm::dot(Q, D));

    //u + v < 1 && u >0 && v >0
    if( u < 0.0 || u > 1.0)
        return false;

    if( v < 0.0 || u + v > 1.0)
        return false;

    float t = f * glm::dot(Q, e2);

    if (t > 1 && t < d) {
        d = t;
        return true;
    }

    return false;

    //Direction norm(glm::normalize(glm::cross(edge1, edge2)));
}









