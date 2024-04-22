#pragma once
#include "line.h"
#include "geometry.h"
#include "tgaimage.h"
#include "Tool.h"
#include "model.h"

void Triangle(std::vector<vec3>& veters, std::vector<vec2> colorVeters, double lighter,
	TGAImage& image, vec2 screenSize, std::vector<std::vector<double> >& z_buffer, Model model);
