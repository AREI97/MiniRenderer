#include "line.h"

void Line(double x0, double y0, double x1, double y1, TGAColor color, TGAImage& image) {
	double step = 0.001;
	for (double t = 0; t <= 1; t+=step) {
		double drawX = x0 + (x1 - x0) * t;
		double drawY = y0 + (y1 - y0) * t;
		image.set(drawX, drawY, color);
	}
}
