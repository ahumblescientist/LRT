#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec.h"
#include "material.h"

class Sphere : public Hittable {
	public:
		double radius;
		Point3D center;
		shared_ptr<Material> mat;
		Sphere(double r, Point3D c, shared_ptr<Material> mat) : radius(r), center(c), mat(mat) {}
		bool hit(Ray &r, Interval interval, Hit_record &rec) {
			Vec3D Q = center - r.origin;
			double a = r.d * r.d;
			double b = -2 * Q * r.d;
			double c = Q * Q - radius * radius;
			double t;
			if(b*b - 4*a*c < 0) {
				return false;
			} else {
				t = (-b - sqrt(b*b - 4*a*c)) / (2*a);
				if(!interval.surrounds(t)) {
					t = (-b + sqrt(b*b - 4*a*c)) / (2*a);
					if(!interval.surrounds(t)) {
						return false;
					}
				}
			}
			rec.p = r.at(t);
			Vec3D outward_normal = unit(r.at(t) - center);
			rec.t = t;
			rec.mat = mat;
			rec.set_face_normal(r, outward_normal);
			return true;
		}
};

#endif
