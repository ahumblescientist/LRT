#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec.h"
#include "ray.h"
#include "constants.h"

class Material;

class Hit_record { 
	public:
		Point3D p;
		Vec3D normal;
		double t;
		bool isFront;
		shared_ptr<Material> mat;
		void set_face_normal(Ray &r, Vec3D outward_normal) {
			isFront = (r.d * outward_normal < 0.0);
			normal = isFront ? outward_normal : -outward_normal;
		}
};

class Hittable {
	public:
		virtual ~Hittable() = default;
		virtual bool hit(Ray &r, Interval, Hit_record &rec) = 0;
};

#endif
