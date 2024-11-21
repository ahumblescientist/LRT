#ifndef COLOR_H
#define COLOR_H

#include "vec.h"
#include "constants.h"
#include <fstream>

using Color = Vec3D;

double linearToGamma(double c) {
	if(c > 0) {
		return std::sqrt(c);
	}
	return 0;
}

void writeColor(std::ostream &out, Color &c) {
	double r = linearToGamma(c.x);
	double g = linearToGamma(c.y);
	double b = linearToGamma(c.z);
	int ir = int(r * 255.00L);
	int ig = int(g * 255.00L);
	int ib = int(b * 255.00L);
	out << ir << " " << ig << " " << ib << "\n";
}

#endif
