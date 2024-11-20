#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <limits>
#include <memory>
#include <iostream>
#include <cmath>
#include <random>

using std::make_shared;
using std::shared_ptr;

const double pi = 3.1415926535;
const double infinity = std::numeric_limits<double>::infinity();

double random_double() {
	static std::uniform_real_distribution<double> distribution(0l, 1.0l);
	static std::mt19937 generator;
	return distribution(generator);
}

double random_double(double min, double max) {
	return min + (max-min)*random_double();
}

#define degrees_to_radians(deg) (pi / (180.0l) * (double) deg)

#include "vec.h"
#include "color.h"
#include "ray.h"
#include "interval.h"


Vec3D random_vec() {
	return Vec3D(random_double(), random_double(), random_double());
}


Vec3D random_vec(double min, double max) {
	return Vec3D(random_double(min, max), random_double(min, max), random_double(min, max));
}

Vec3D random_unit_vec() {
	while(1) {
		Vec3D v = random_vec(-1, 1);
		if(0 < v.magnitude() && v.magnitude() <= 1) {
			return v/v.magnitude();
		}
	}
}

Vec3D random_on_sphere(Vec3D normal) {
	Vec3D v = random_unit_vec();
	if(v * normal < 0) {
		return -v;
	}
	return v;
}


#endif
