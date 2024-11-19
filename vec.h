#ifndef VEC_H
#define VEC_H

#include <math.h>
#include <fstream>


class Vec3D {
	public:
		double x, y, z;
		Vec3D(double a, double b, double c) : x(a), y(b), z(c) {}
		Vec3D() : x(0), y(0), z(0) {}
		Vec3D operator-() const { return Vec3D(-x, -y, -z); }
		Vec3D &operator+=(Vec3D Add) {
			x = x + Add.x;
			y = y + Add.y;
			z = z + Add.z;
			return *this;
		}
		Vec3D &operator*=(double c) {
			x *= c;
			y *= c;
			z *= c;
			return *this;
		}
		Vec3D &operator/=(double c) {
			x /= c;
			y /= c;
			z /= c;
			return *this;
		}
		double magnitude() {
			double squared = x*x + y*y + z*z;
			return sqrt(squared);
		}
};

using Point3D = Vec3D;

Vec3D operator*(double, Vec3D);
Vec3D operator*(Vec3D, double);
Vec3D operator/(Vec3D, double);
Vec3D operator-(Vec3D, Vec3D);
Vec3D operator+(Vec3D, Vec3D);
Vec3D normal(Vec3D &);

#endif
