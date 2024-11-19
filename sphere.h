#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec.h"

class Sphere : public Hittable {
	public:
		double radius;
		Point3D center;
		Sphere(double r, Point3D c) : radius(r), center(c) {}
		bool hit(Ray &r, double min, double max, Hit_record &rec) {
			Vec3D Q = center - r.origin;
			double a = r.d * r.d;
			double b = -2 * Q * r.d;
			double c = Q * Q - radius * radius;
			double t;
			if(b*b - 4*a*c < 0) {
				return false;
			} else {
				t = (-b - sqrt(b*b - 4*a*c)) / (2*a);
				if(t < min || t > max) {
					t = (-b + sqrt(b*b - 4*a*c)) / (2*a);
					if(t < min || t > max) {
						return false;
					}
				}
			}
			rec.p = r.at(t);
			Vec3D outward_normal = unit(r.at(t) - center);
			rec.t = t;
			rec.set_face_normal(r, outward_normal);
			return true;
		}
};

#endif
