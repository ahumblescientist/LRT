#include "vec.h"

std::ostream& operator<<(std::ostream& out, Vec3D v) {
	return (out << v.x << " " << v.y << " " << v.z);	
}

Vec3D operator+(Vec3D v1, Vec3D v2) {
	return Vec3D(v1.x + v2.x, v1.y + v2.y, v1.z+v2.z);
}

Vec3D operator-(Vec3D v1, Vec3D v2) {
	return Vec3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3D operator*(Vec3D v, double c) {
	return Vec3D(v.x * c, v.y * c, v.z * c);
}

Vec3D operator*(double c, Vec3D v) {
	return Vec3D(v.x * c, v.y * c, v.z * c);
}

Vec3D operator/(Vec3D v, double c) {
	return Vec3D(v.x / c, v.y / c, v.z / c);
}

double operator*(Vec3D v1, Vec3D v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vec3D operator^(Vec3D v1, Vec3D v2) {
	return Vec3D(v1.y * v2.z - v2.y * v1.z, -(v1.x*v2.z - v2.x * v1.z), v1.x*v2.y - v2.x * v1.y);
}

Vec3D unit(Vec3D v) {
	return v/v.magnitude();
}
