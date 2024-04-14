#include "tgaimage.h"
#include "line.h"
#include "model.h"
#include "transformer.h"
#include "Triangle.h"
#include "Tool.h"
#include <iostream>
const TGAColor white = { 255, 255, 255,255};
const TGAColor red = { 0, 0, 255,255};
int main(int argc, char** argv) {
    int width = 1000;
    int height = 1000;
    vec3 lightV = { 0,0.8,0.8};
    TGAImage image(width, height, TGAImage::RGB);
    Model myModel("./tinyrenderer/obj/african_head/african_head.obj");

    for (int i = 0; i < myModel.nfaces(); i++) {
        std::vector<vec2> veters;
        std::vector<vec3> worldVeters;
        for (int j = 0; j < 3; j++) {
            
            vec2 temp = { myModel.vert(i, j).x, myModel.vert(i, j).y };
            vec3 wTemp = { myModel.vert(i, j).x, myModel.vert(i, j).y ,myModel.vert(i,j).z };
            world2screen(temp, width, height);
            veters.push_back(temp);
            worldVeters.push_back(wTemp);
        }
        vec3 n = computeN(worldVeters);
        double delta = n * lightV;
        TGAColor color = white;
        if (delta > 0) {
            color = changeColor(white, delta);
            Triangle(veters, color, image);
        }
    }
    //vec2 t0 = { 10, 20 };
    //vec2 t1 = { 50, 70 };
    //vec2 t2 = { 40, 90 };
    //std::vector<vec2> veters = { t0, t1, t2 };
    //Triangle(veters, white, image);
    image.write_tga_file("output.tga");
    return 0;
}