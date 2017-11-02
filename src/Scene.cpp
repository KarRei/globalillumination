#include "Scene.h"

Scene::Scene()
{
    createRoom();
}

/*Scene::~Scene()
{

}*/

void Scene::createRoom(){
    float lambertian = 0.0;
    float specular = 1.0;

    //Defining points in room
    glm::vec3 aTop(13.0f, 0.0f, 5.0f), aBottom(13.0f, 0.0f, -5.0f);
    glm::vec3 bTop(10.0f, 6.0f, 5.0f), bBottom(10.0f, 6.0f, -5.0f);
    glm::vec3 cTop(10.0f, -6.0f, 5.0f), cBottom(10.0f, -6.0f, -5.0f);
    glm::vec3 dTop(0.0f, 6.0f, 5.0f), dBottom(0.0f, 6.0f, -5.0f);
    glm::vec3 eTop(0.0f, -6.0f, 5.0f), eBottom(0.0f, -6.0f, -5.0f);
    glm::vec3 fTop(-3.0f, 0.0f, 5.0f), fBottom(-3.0f, 0.0f, -5.0f);

    //Create surfaces
    Surface wall1(ColorDbl(glm::vec3(1.0f, 0.0f, 0.0f)), lambertian); //red
    Surface wall2(ColorDbl(glm::vec3(0.0f, 0.0f, 1.0f)), lambertian); //blue
    Surface wall3(ColorDbl(glm::vec3(0.0f, 1.0f, 0.0f)), lambertian); //green
    Surface wall4(ColorDbl(glm::vec3(1.0f, 1.0f, 0.0f)), lambertian); //yellow
    Surface wall5(ColorDbl(glm::vec3(1.0f, 0.0f, 1.0f)), lambertian); //purple
    Surface wall6(ColorDbl(glm::vec3(1.0f, 0.6f, 0.0f)), lambertian); //orange
    Surface bottomTop(ColorDbl(glm::vec3(1.0f, 1.0f, 1.0f)), lambertian); //white

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

    //Defining points of Tetrahedron (consists of 4 triangles)
    glm::vec3 tetra1(11.0f, 4.0f, 3.0f);
    glm::vec3 tetra2(10.0f, 5.0f, -1.0f);
    glm::vec3 tetra3(10.0f, 0.0f, -1.0f);
    glm::vec3 tetra4(12.0f, 3.0f, -1.0f);

    Surface tetra_col(ColorDbl(glm::vec3(0.0f, 1.0f, 1.0f)), specular); //turquose

    Triangle tetra_tri1(tetra1, tetra2, tetra3, tetra_col);
    Triangle tetra_tri2(tetra1, tetra3, tetra4, tetra_col);
    Triangle tetra_tri3(tetra1, tetra4, tetra2, tetra_col);
    Triangle tetra_tri4(tetra2, tetra4, tetra3, tetra_col);

    triangles.push_back(tetra_tri1);
    triangles.push_back(tetra_tri2);
    triangles.push_back(tetra_tri3);
    triangles.push_back(tetra_tri4);


    //Defining points of Sphere
    Surface sphere_color(ColorDbl(glm::vec3(1.0f, 0.01f, 0.5f)), specular); //pink

    Sphere s1(glm::vec3 (11.0f, -3.0f, 0.0f), 1.0f, sphere_color );

    spheres.push_back(s1);



    //Light


}

void Scene::rayIntersection(Ray& r)
{
    //snygga till n�dl�sningen!!

    //Loop through all triangles in scene
    //Loop the current triangle
    Triangle* temp;
    float distance = 1000.0f; //Arbitrary large number to check against distance to triangle
    bool sphere_intersection = false;

    //Test triangle intersection
    for(vector<Triangle>::iterator it = triangles.begin(); it != triangles.end(); it++)
    {
        //Passing it just passes an itterator object, it* passes the underlying object,
        //&(*it) passes the address to that underlying object
        // If true then there is an intersection!
        if (tryIntersectionTriangle(glm::normalize(r.getDirection()), r.getStart(), *it, distance))
            temp = &(*it);

    }

    //test sphere intersection
    Sphere* temp_sp;
    for(vector<Sphere>::iterator it = spheres.begin(); it != spheres.end(); it++)
    {
        if (tryIntersectionSphere(glm::normalize(r.getDirection()), r.getStart(), *it, distance))
        {
            temp_sp = &(*it);
            sphere_intersection = true;
        }
    }

    if (sphere_intersection){
        // check if temp is specular or diffuse
        // if diffuse -> set color to the pixel
        // if specular -> call this method again

        r.setColor(temp_sp->getColor());

    }
    //ENDED HERE
    //intersection with triangle
    else {
        float model = temp->getBRDF();

        //if ^ is specular -> getReflectedRay(r)
        if (model == 1.0f)
        {
            Ray rr = temp->getReflectedRay(r);
            rayIntersection(rr);

        }
        else // if diffuse -> set color to the pixel
        {
            r.setColor(temp->getColor());
        }
    }

}


bool Scene::tryIntersectionSphere(glm::vec3 direction, glm::vec3 start, Sphere& sph, float& distance)
{
    const float ZERO = 0.0000001;
    float radius = sph.getRadius();
    glm::vec3 center = sph.getPosition();

    float b = glm::dot(2.0f * direction , start - center );
    float c = glm::dot( start - center , start - center ) - glm::pow(radius, 2);

    float d1 = -(b / 2.0f) + glm::sqrt(glm::pow( (b / 2.0), 2) - c);
    float d2 = -(b / 2.0f) - glm::sqrt(glm::pow( (b / 2.0), 2) - c);

    glm::vec3 x;

    if((glm::pow( (b / 2.0), 2) - c) < ZERO)
       return false;

    //Sphere behind camera
    if (d1 <= 0 && d2 <= 0) {
        return false;
    }

    else if (d1 < d2) {
        x = start + d1*direction;
        distance = glm::distance(start, x );
        return true;
    }

    else if (d2 < d1) {
        x = start + d2*direction;
        distance = glm::distance(start, x );
        return true;
    }

    //camera inside the sphere
    else {
        x = start + d2*direction;
        distance = glm::distance(start, x );
        return true;
    }

    return false;
}

bool Scene::tryIntersectionTriangle(glm::vec3 D, glm::vec3 start, Triangle& tri, float& d)
{
    //M�ller Trumbore Algorithm
    const float ZERO = 0.0000001;
    glm::vec3 e1, e2, T, P, Q;
    e1 = tri.getPoint(2) - tri.getPoint(1);
    e2 = tri.getPoint(3) - tri.getPoint(1);

    T = start - tri.getPoint(1);
    P = glm::cross(D, e2);
    Q = glm::cross(T, e1);

    double a = glm::dot(e1, P);

    // For float numbers, don't check if they are exactly the same. Check whether their difference is very small
    if (a > -ZERO && a < ZERO) {
        return false;
    }
    double f = 1.0/a;
    double u = glm::dot(T, P) * f;
    double v = glm::dot(D, Q) * f;

    //u + v < 1 && u >0 && v >0
    if( u < 0.f || u > 1.f)
        return false;

    if( v < 0.f || u + v > 1.f)
        return false;

    double t = glm::dot(e2, Q) * f;

    // if the intersection point lies behind the imageplane and the distance is smaller than a previous tringle
    if (t > 1.f && t < d) {
        d = (float)t;
        return true;
    }

    return false;

}









