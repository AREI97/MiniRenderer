//#include "tgaimage.h"
//#include "line.h"
//#include "model.h"
//#include "transformer.h"
//#include "Triangle.h"
//#include "Tool.h"
//#include <iostream>
//const TGAColor white = { 255, 255, 255,255};
//const TGAColor red = { 0, 0, 255,255};
//int main(int argc, char** argv) {
//    int width = 1000;
//    int height = 1000;
//    vec3 lightV = { 0,0,-1};
//    TGAImage image(width, height, TGAImage::RGB);
//    Model myModel("./tinyrenderer/obj/african_head/african_head.obj");
//    vec3 camera = { 0,0, 2 };
//    vec2 screenSize = { width,height };
//    std::vector<std::vector<double> > z_buffer(width+10, std::vector<double>(height+10, -std::numeric_limits<double>::max()));
//    mat<4, 4> projectionMat = mat<4, 4>::identity();
//    mat<4, 4> viewMat = ViewMat(width, height, 255);
//    projectionMat[3][2] = -1.f / camera.z;
//    for (int i = 0; i < myModel.nfaces(); i++) {
//        std::vector<vec3> worldVeters;
//        std::vector<vec3> veters;
//        std::vector<vec2> colorVeters;
//        for (int j = 0; j < 3; j++) {
//            vec2 colorTemp = myModel.uv(i, j);
//            vec3 wTemp = { myModel.vert(i, j).x, myModel.vert(i, j).y ,myModel.vert(i,j).z };
//
//            vec3 temp = reduceDim(projectionMat * addDim(wTemp));
//            temp = reduceDim(viewMat * addDim(temp));
//            worldVeters.push_back(wTemp);
//            veters.push_back(temp);
//            colorVeters.push_back(colorTemp);
//        }
//        vec3 n = computeN(worldVeters);
//        double delta = n * lightV;
//
//        Triangle(veters, colorVeters,delta, image,screenSize,z_buffer,myModel);
//
//    }
//    //vec3 t0 = { 10, 20,0 };
//    //vec3 t1 = { 50, 70,0 };
//    //vec3 t2 = { 40, 90,0 };
//   /* world2screen(t0, width, height);
//    world2screen(t1, width, height);
//    world2screen(t2, width, height);*/
//   /* std::vector<vec3> veters = { t0, t1, t2 };
//    Triangle(veters, white, image,screenSize,z_buffer);*/
//    image.write_tga_file("output.tga");
//    return 0;
//}