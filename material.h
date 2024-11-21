#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "constants.h"
#include "hittable.h"

class Material {
	public:
		virtual ~Material() = default;
		virtual bool scatter(Ray &r, Hit_record &rec, Color &attenuation, Ray &scattered) {
			return false;
		}
};

class Lambertian : public Material {
	public:
		Color albedo;
		Lambertian(Color albedo) : albedo(albedo) {}
		bool scatter(Ray &r, Hit_record &rec, Color &attenuation, Ray &scattered) {
			attenuation = albedo;
			Vec3D scattering_dir = rec.normal + random_unit_vec();
			while(scattering_dir.near_zero()) {
				scattering_dir = rec.normal + random_unit_vec();
			}
			scattered = Ray(rec.p, scattering_dir);
			return true;
		}
};

class Metal : public Material {
	public:
		Color albedo;
		Metal(Color albedo) : albedo(albedo) {}
		bool scatter(Ray &r, Hit_record &rec, Color &attenuation, Ray &scattered) {
			attenuation = albedo;
			Vec3D reflected = reflect(r.d, rec.normal);
			scattered = Ray(rec.p, reflected);
			return true;
		}
};

#endif
