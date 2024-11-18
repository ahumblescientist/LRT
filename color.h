#ifndef COLOR_H
#define COLOR_H

#include "vec.h"
#include <fstream>

using Color = Vec3D;

void writeColor(std::ostream &out, Color &c) {
	double r = c.x;
	double g = c.y;
	double b = c.z;
	int ir = int(r * 255.00L);
	int ig = int(g * 255.00L);
	int ib = int(b * 255.00L);
	out << ir << " " << ig << " " << ib << "\n";
}

#endif
