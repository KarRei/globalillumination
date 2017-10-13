#include "Camera.h"

Camera::Camera()
{
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

            // V�rden mellan -0.999 och .999 (-1 och 1)
            glm::vec3 imagePlanePosition(0, y*0.002 - 0.999, z*0.002 - 0.999);

            //crete a ray from the eye to current pixel
            Ray r(eye, imagePlanePosition);
            // Launch the ray into the scene. The function will take the reference to the ray and set it's color.
           scene.rayIntersection(r);
           //after rayIntersection r's color (colorDbl) has changes to the triangle color that it hits

           // obviously, if the values of the colordbl is all 0.0, it will be wrong in createImage since we're trying to divide by zero.
           if (z==1 && y == 1) // this has not changed. giving 0.0. SOMETHING IS WRONG IN rayIntersection!!!
            {
                std::cout << std::fixed << std::setprecision(3) << r.getColor().getColorVec().r << endl;
                std::cout << std::fixed << std::setprecision(3) << r.getColor().getColorVec().g << endl;
                std::cout << std::fixed << std::setprecision(3) << r.getColor().getColorVec().b << endl;
            }
            else if (z==100 && y == 100) //This has changed 1.0, 1.0, 0.0 = yellow
            {
                std::cout << std::fixed << std::setprecision(3) << r.getColor().getColorVec().r << endl;
                std::cout << std::fixed << std::setprecision(3) << r.getColor().getColorVec().g << endl;
                std::cout << std::fixed << std::setprecision(3) << r.getColor().getColorVec().b << endl;
            }

            imagePlane[y][z].setColor(r.getColor());

        }
    }

    //delete ray(not nec)
}

void Camera::createImage(const string filename) {
    // Loop through imagePlane, convert the ColorDbl attibutes of the Pixel-objects
    // to a RGB-vector with integer values (in the range 0-255, a colorDbl has values in range 0.0-1.0)

    //Crete image file
    FILE *fp = fopen(filename.c_str(), "wb");
    fprintf(fp, "P3\n%d %d\n255\n", 1000, 1000);

    for (int z = 0; z < max_val; z++) {
        for (int y = 0; y < max_val; y++) {
                //loop through all color channels RGB and find largest intensity value i_max
                //Extract ColorDbl of each pixel and multiply with 255.99/imax

                glm::vec3 RGB;

                float i_max = imagePlane[y][z].getColor().x;

                if (imagePlane[y][z].getColor().y > i_max)
                    i_max = imagePlane[y][z].getColor().y;

                if (imagePlane[y][z].getColor().z > i_max)
                    i_max = imagePlane[y][z].getColor().z;

                RGB.r = (255.99 / i_max)*(imagePlane[y][z].getColor().r);
                RGB.g = (255.99 / i_max)*(imagePlane[y][z].getColor().g);
                RGB.b = (255.99 / i_max)*(imagePlane[y][z].getColor().b);

                // OBS (int) grejerna �r viktiga!
                fprintf(fp, "%d %d %d ", (int)RGB.r, (int)RGB.g, (int)RGB.b);


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
