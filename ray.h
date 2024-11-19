#ifndef RAY_H
#define RAY_H

#include "vec.h"

class Ray {
	public:
		Point3D origin;
		Vec3D d;
		Ray() {}
		Ray(Point3D &o, Vec3D v) : origin(o), d(v) {}
		Point3D at(double c) {
			return origin + d*c;
		}
};

#endif
