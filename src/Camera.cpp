#include "Camera.h"

Camera::Camera()
{
    cout << "constructing camera" << endl;

    eye = glm::vec3(-2.0f, 0.0f, 0.0f);
    for (int i = 0; i < 1000; i++)
        imagePlane[i] = new Pixel[1000];
}

Camera::~Camera()
{
    // VERYTHING CREATED WITH NEW MUST BE DEALLOCATED WITH DELETE
    //dtor
}

void Camera::render(Scene& scene) { // const Scene, so we dont accidentaly change something?
    //loop through the pixels
    //set pixel color from ray

    for (int z =  0; z < max_val; z++) {
        for (int y = 0; y < max_val; y++) {

            glm::vec3 imagePlanePosition(0, y*0.002 - 0.999, z*0.002 - 0.999);

            //crete a ray from the eye to current pixel
            Ray r(eye, imagePlanePosition);

            // Launch the ray into the scene. The function will take the reference to the ray and set it's color.
           scene.rayIntersection(r);

            //Create a new pixel with the color from the ray and store it in imagePlane
            imagePlane[z][y] = Pixel(r.getColor());
        }
    }

    //delete ray(not nec)
}

void Camera::createImage(const string filename) {
    // Loop through imagePlane, convert the ColorDbl attibutes of the Pixel-objects
    // to a RGB-vector with integer values (in the range 0-255, a colorDbl has values in range 0.0-1.0)

    //Crete image file
    //glm::vec3 imagePlaneRGB[1000][1000]; // kanske ocks� f�r stor? g�r det att inte ha en ny array...?

    FILE *fp = fopen(filename.c_str(), "wb");
    fprintf(fp, "P3\n%d %d\n255\n", 1000, 1000);

    for (int z = 0; z < max_val; z++) {
        for (int y = 0; y < max_val; y++) {
                //loop through all color channels RGB and find largest intensity value i_max
                //Extract ColorDbl of each pixel and multiply with 255.99/imax

                glm::vec3 RGB;

                int i_max = 0;
                //if (imagePlane[y][z].getColor[i] > i_max)
                i_max = imagePlane[y][z].getColor().x;

                if (imagePlane[y][z].getColor().y > i_max)
                    i_max = imagePlane[y][z].getColor().y;

                if (imagePlane[y][z].getColor().z > i_max)
                    i_max = imagePlane[y][z].getColor().z;

                //imagePlaneRGB[y][z].x = (int)((255.99 / i_max)*(imagePlane[y][z].getColor().x));
                //imagePlaneRGB[y][z].y = (int)((255.99 / i_max)*(imagePlane[y][z].getColor().y));
                //imagePlaneRGB[y][z].z = (int)((255.99 / i_max)*(imagePlane[y][z].getColor().z));

                RGB.r = (int)((255.99 / i_max)*(imagePlane[y][z].getColor().x));
                RGB.g = (int)((255.99 / i_max)*(imagePlane[y][z].getColor().y));
                RGB.b = (int)((255.99 / i_max)*(imagePlane[y][z].getColor().z));

                fprintf(fp, "%d %d %d ", RGB.r, RGB.g, RGB.b);


        }
    }

    fclose(fp);

    //Write to file
    //writeToFile("image.ppm", imagePlaneRGB);

}


/*void Camera::writeToFile(const string filename, glm::vec3 img[1000][1000]) {

    cout << "hej" << endl;

    FILE *fp = fopen(filename.c_str(), "wb");
    fprintf(fp, "P3\n%d %d\n255\n", 1000, 1000);
    for (int z = 0; z < 1000; z++) {
        for (int y = 0; y < 1000; y++) {
            int red = img[z][y].r;
            int green = img[z][y].g;
            int blue = img[z][y].b;
            fprintf(fp, "%d %d %d ", (red), (green), (blue));
        }
    }
    fclose(fp);
} */
