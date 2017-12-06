#include "Scene.h"

Scene::Scene()
{
    createRoom();
}

/*Scene::~Scene()
{

}*/

void Scene::createRoom(){
    /*float lambertian = 0.2f;
    float specular = 1.0f;
    float light = 0.0f;*/

    //ROOM
    //Defining points in room
    glm::vec3 aTop(13.0f, 0.0f, 5.0f), aBottom(13.0f, 0.0f, -5.0f);
    glm::vec3 bTop(10.0f, 6.0f, 5.0f), bBottom(10.0f, 6.0f, -5.0f);
    glm::vec3 cTop(10.0f, -6.0f, 5.0f), cBottom(10.0f, -6.0f, -5.0f);
    glm::vec3 dTop(0.0f, 6.0f, 5.0f), dBottom(0.0f, 6.0f, -5.0f);
    glm::vec3 eTop(0.0f, -6.0f, 5.0f), eBottom(0.0f, -6.0f, -5.0f);
    glm::vec3 fTop(-3.0f, 0.0f, 5.0f), fBottom(-3.0f, 0.0f, -5.0f);

    //Create surfaces
    Surface wall1(ColorDbl(glm::vec3(1.0f, 0.0f, 0.0f))); //red -->
    Surface wall2(ColorDbl(glm::vec3(0.0f, 0.0f, 1.0f))); //blue -->
    Surface wall3(ColorDbl(glm::vec3(0.0f, 1.0f, 0.0f))); //green -->
    Surface wall4(ColorDbl(glm::vec3(1.0f, 1.0f, 0.0f))); //yellow -->
    Surface wall5(ColorDbl(glm::vec3(1.0f, 1.0f, 1.0f))); //white -->
    Surface wall6(ColorDbl(glm::vec3(1.0f, 0.6f, 0.0f))); //orange -->
    Surface bottomTop(ColorDbl(glm::vec3(1.0f, 1.0f, 1.0f))); //white


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

    //OBJECTS
    //Defining points of Tetrahedron (consists of 4 triangles)
    glm::vec3 tetra1(3.0f, -1.0f, 0.0f);
    glm::vec3 tetra2(4.0f, -3.0f, -1.0f);
    glm::vec3 tetra3(5.0f, -2.0f, -1.0f);
    glm::vec3 tetra4(4.5f, -2.5f, 1.0f);

    Surface tetra_col(ColorDbl(glm::vec3(0.0f, 1.0f, 1.0f))); //turquose
    Surface sphere_color(ColorDbl(glm::vec3(1.0f, 0.01f, 0.5f))); //pink

    Triangle tetra_tri1(tetra1, tetra3, tetra2, sphere_color);
    Triangle tetra_tri2(tetra1, tetra4, tetra3, sphere_color);
    Triangle tetra_tri3(tetra1, tetra2, tetra4, sphere_color);
    Triangle tetra_tri4(tetra2, tetra3, tetra4, sphere_color);

    triangles.push_back(tetra_tri1);
    triangles.push_back(tetra_tri2);
    triangles.push_back(tetra_tri3);
    triangles.push_back(tetra_tri4);


    //Defining points of Sphere

    //Surface sphere_color(ColorDbl(glm::vec3(1.0f, 1.0f, 1.0f))); //white
    Sphere s1(glm::vec3 (4.0f, 2.0f, -2.0f), 1.0f, tetra_col );
    spheres.push_back(s1);

    //LIGHT

    glm::vec3 light1(4.0f, 1.0f, 4.99f);
    glm::vec3 light2(4.0f, -1.0f, 4.99f);
    glm::vec3 light3(6.0f, -1.0f, 4.99f);
    glm::vec3 light4(6.0f, 1.0f, 4.99f);

    //white light
    Surface surface_light(ColorDbl(glm::vec3(1.0f, 1.0f, 1.0f)), 2); //white

    Triangle t_light1(light1, light4, light3, surface_light);
    Triangle t_light2(light1, light3, light2, surface_light);

    triangles.push_back(t_light1);
    triangles.push_back(t_light2);

    lightSource = Light();
}


glm::vec3 Scene::rayIntersection(Ray &r, int nr_iterations)
{
    glm::vec3 hitPoint_tri = glm::vec3(100.f);
    glm::vec3 hitPoint_sph = glm::vec3(100.f);
    glm::vec3 color(0.0f);

    //lists with intersected objects
    list<TriangleIntersection> triangle_list = firstIntersectedTriangle(r);
    list<SphereIntersection> sphere_list = firstIntersectedSphere(r);

    float length_tri = 10000000.0f;
    float length_sph = 10000000.0f;

    if(triangle_list.size() > 0)
        length_tri = glm::distance(triangle_list.front().point, r.getStart());

    if (sphere_list.size() > 0)
        length_sph = glm::distance(sphere_list.front().point, r.getStart());

    //Distance no nearest triangle and spheere
    Triangle nearest_tri = triangle_list.front().triangle;
    hitPoint_tri = triangle_list.front().point;

    Sphere nearest_sph = sphere_list.front().sphere;
    hitPoint_sph = sphere_list.front().point;

    // TRIANGLE closest
    if (length_tri < length_sph)
    {
        //Only Lambertian materials
        //The radiance of a diffuse emitter does not depend on direction
        Surface surf = nearest_tri.getSurface();

        //If light source
        if(surf.getModel() == 2)
            return surf.getColor().getColorVec();//*(1/tri_distance)

        Ray reflected_ray = nearest_tri.getReflectedRay(r, hitPoint_tri);

        glm::vec3 light_contribution = castShadowRay(r, nearest_tri.getNormal(), hitPoint_tri );

        float angle = glm::angle(glm::normalize(r.getDirection()), nearest_tri.getNormal());

        glm::vec3 intensity = nearest_tri.getColor().getColorVec()*(0.3f); //* (0.8f / 3.1415f);

        //local lighting contribution
        color += intensity;
        color *= light_contribution;


        //Diffuse
        //Continue reflections
        if (nr_iterations < MAX_ITERATIONS)
        {
            nr_iterations++;
            color += rayIntersection(reflected_ray, nr_iterations)* cos(angle); // / 3.1415f)*cos(angle); //
        }
    }




    //SPHERE //a sphere is closest
    else if (length_sph < length_tri)
    {
        Surface surf = nearest_sph.getSurface();

        Ray reflected_ray = nearest_sph.getReflectedRay(r, hitPoint_sph);

        glm::vec3 light_contribution = castShadowRay(r, nearest_sph.getNormal(hitPoint_sph), hitPoint_sph );

        float angle = glm::angle(glm::normalize(r.getDirection()), nearest_sph.getNormal(hitPoint_sph));

        glm::vec3 intensity = nearest_sph.getColor().getColorVec()*(0.3f);//*(0.8f / 3.1415f);

        color += intensity;
        color *= light_contribution ;

        //Diffuse
        //Continue reflections
        if (nr_iterations < MAX_ITERATIONS )
        {
            nr_iterations++;
            color += rayIntersection(reflected_ray, nr_iterations)*cos(angle);// / 3.1415f ); //
        }
    }

    return color;
}

//This function should only return the first intersected triangle
list<TriangleIntersection> Scene::firstIntersectedTriangle(Ray r)
{
    list<TriangleIntersection> intersection_list = {};

    glm::vec3 rayStart = r.getStart();

    for(vector<Triangle>::iterator it = triangles.begin(); it != triangles.end(); it++)
    {
        TriangleIntersection ti;
        glm::vec3 temp_hPoint;

        //problem, returnerar 0 ibland då den inte går in i if-satsen
        if ( tryIntersectionTriangle( glm::normalize( r.getDirection() ), rayStart, *it, temp_hPoint ))
        {
            ti.triangle = *it;
            ti.point = temp_hPoint + 0.001f * it->getNormal();
            intersection_list.push_back(ti);
        }
    }

    //Sort list closest to rayStart()
    intersection_list.sort( [&rayStart](const TriangleIntersection &a, const TriangleIntersection &b ) {
        return glm::length( a.point - rayStart ) < glm::length( b.point - rayStart );
    });

    return intersection_list;
}

list<SphereIntersection> Scene::firstIntersectedSphere(Ray r)
{
    list<SphereIntersection> intersection_list = {};
    glm::vec3 rayStart = r.getStart();

    for(vector<Sphere>::iterator it = spheres.begin(); it != spheres.end(); it++)
    {
        SphereIntersection si;
        glm::vec3 temp_hPoint;
        if (tryIntersectionSphere(glm::normalize(r.getDirection()), rayStart, *it, temp_hPoint))
        {
            si.sphere = *it;
            si.point = temp_hPoint + 0.001f * it->getNormal(temp_hPoint);
            intersection_list.push_back(si);
        }
    }
    return intersection_list;
}


glm::vec3 Scene::castShadowRay(Ray& rayIncoming, glm::vec3 normal, glm::vec3 hitPoint)
{
    glm::vec3 directlight_contribution = glm::vec3(0.0f);
    for (int i = 0; i < 4; i++){
    //glm::vec3 directlight_contribution(0.0f);
    glm::vec3 randomPointOnLight = lightSource.getRandomPoint();

    Ray light_ray(hitPoint, glm::normalize( randomPointOnLight - hitPoint ));
    float length_light = abs(glm::distance( hitPoint, randomPointOnLight ));

    list<TriangleIntersection> triangle_list = firstIntersectedTriangle( light_ray );
    list<SphereIntersection> sphere_list = firstIntersectedSphere( light_ray );

    // Nearest triangle
    TriangleIntersection nearets_tri = triangle_list.front();
    //SphereIntersection nearets_sph = sphere_list.front();
    //check if triangle or sphere is closest, we know that hitPoi4.99nt lies on the closest object
    float length_tri = 10000000.0f;
    float length_sph = 10000000.0f;

    if (triangle_list.size() > 0)
        length_tri = abs(glm::distance( hitPoint, nearets_tri.point ));

    if (sphere_list.size())
        length_sph = abs(glm::distance( hitPoint, sphere_list.front().point ));

//        if ( abs(length_tri - length_light) < 0.01 )
    //shadow
    if ( length_tri < length_light || length_sph < length_light ){
        directlight_contribution += glm::vec3 ( 0.0f );
        //continue;
    }
    else{

        //for point light source, attenuation depending on light distance
        float attenuation = 1.f;

        if(length_light > 1.f)
            attenuation = 1.f / sqrt(length_light);

        //Point in direct light
        //kd*cos()
        glm::vec3 A = glm::normalize(light_ray.getDirection());
        float C = max(0.0f, glm::dot(normal, A));

        Surface light_surface = lightSource.getSurface();

        directlight_contribution += ( glm::vec3(20.0f) * C * 0.2f* attenuation );
    }
    }

    return directlight_contribution / 4.f;
}


bool Scene::tryIntersectionSphere(glm::vec3 direction, glm::vec3 start, Sphere& sph, glm::vec3& iPoint)
{
    const float ZERO = 0.0000000001;
    float radius = sph.getRadius();
    glm::vec3 center = sph.getPosition();

    float b = glm::dot( 2.0f * direction , start - center );
    float c = glm::dot( start - center , start - center ) - glm::pow( radius, 2 );

    float d1 = - ( b / 2.0f ) + glm::sqrt( glm::pow( (b / 2.0), 2) - c );
    float d2 = - ( b / 2.0f ) - glm::sqrt( glm::pow( (b / 2.0), 2) - c );


    if((glm::pow( (b / 2.0), 2) - c) < ZERO )
       return false;

    //Sphere behind camera
    if ( d1 <= 0 && d2 <= 0 ) {
        return false;
    }

    else if ( d1 < d2 ) {
        iPoint = start + d1*direction;
        //distance = glm::distance( start, iPoint );
        //Never happens
        return true;
    }

    else if ( d2 < d1 ) {
        iPoint = start + d2*direction;
        //distance = glm::distance( start, iPoint );
        //happens
        return true;
    }

    //camera inside the sphere
    else {
        iPoint = start + d2*direction;
        //distance = glm::distance( start, iPoint );
        //happens
        return true;
    }
    return false;
}

bool Scene::tryIntersectionTriangle(glm::vec3 D, glm::vec3 start, Triangle& tri, glm::vec3& iPoint)
{
    //Möller Trumbore Algorithm
    const float ZERO = 0.000000001;
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
    if ( t > ZERO && t < 10000000.f) {
        iPoint = start + D*(float)t;

        return true;
    }

    return false;
}









