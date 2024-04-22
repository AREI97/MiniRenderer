#include "Triangle.h"
#include "transformer.h"
#include <algorithm>

struct {
	bool operator()(vec3 a, vec3 b) const {
		return a.y < b.y;
	}
} cmp;

void Triangle(std::vector<vec3>& veters, std::vector<vec2> colorVeters, double lighter,
	TGAImage& image, vec2 screenSize, std::vector<std::vector<double> >& z_buffer,Model model){
	//根据三角形生成边框box
	std::vector<double> box = generateBox(veters,screenSize);
	//遍历边框的点 根据z-buffer决定是否渲染三角形中的点
	double step = 0.5;
	for (double x = box[0]; x < box[1]; x+=step) {
		for (double y = box[3]; y < box[2]; y+=step) {
			int z = 0;
			vec3 P = { x, y, 0};
			vec2 pUv = {0,0};
			TGAColor pColor;
			vec3 massCenter = ComputeGravity(veters,P);
			
			if (IsInSide(massCenter)) {

				for (int i = 0; i < 3; i++) {
					P.z += veters[i].z * massCenter[i];
					pUv = pUv + colorVeters[i] * massCenter[i];
				}
				if (z_buffer[x][y] < P.z) {
					z_buffer[x][y] = P.z;
					pUv.x *= 1024;
					pUv.y *= 1024;
					pColor = model.diffuse().get(pUv.x, pUv.y);
					if(lighter > 0)
					pColor = changeColor(pColor, lighter);
					image.set(P.x, P.y, pColor);
				}
			}
		}
	}
}