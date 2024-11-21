#ifndef CAMERA_H
#define CAMERA_H

#include "constants.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"

class Camera {

	public:
		double aspect_ratio = 1.6;
		int image_width = 100;
		int sample_number = 10;
		int max_depth = 10;
		void render(Hittable &world) {
			init();	
			std::ofstream output("out.ppm");
			output << "P3\n" << " " << image_width << " " << image_height << "\n255\n";
			for(int i=0;i<image_height;i++) {
				std::cout << "still going " << i << std::endl;
				for(int j=0;j<image_width;j++) {
					Color color;
					for(int s = 0;s<sample_number;s++) {
						Ray r = getRay(j, i);
						color += rayColor(r, world, 1);
					}
					color = color / double(sample_number);
					writeColor(output, color);
				}
			}
		}
	private:
		Point3D center;
		int image_height;
		Vec3D deltaU;
		Vec3D deltaV;
		Vec3D pixel00;
		void init() {
			center = Point3D(0, 0, 0);
			image_height = double(image_width) / aspect_ratio;
			double vph = 2.0l;
			double vpw = vph * (double(image_width)/double(image_height));
			std::cout << vph << " " << vpw;
			Vec3D focal(0, 0, -1);
			Vec3D vecU(vpw, 0, 0);
			Vec3D vecV(0, -vph, 0);
			deltaU = vecU/double(image_width);
			deltaV = vecV/double(image_height);
			pixel00 = center - (vecV/2) - (vecU/2) + focal + (0.5l * deltaU) + (0.5l * deltaV);
		}
		Ray getRay(int x, int y) {
			Vec3D offset = sample_square();
			Vec3D loc = pixel00 + (offset.x + double(x)) * deltaU + (offset.y + double(y)) * deltaV;
			return Ray(center, loc-center);
		}
		Vec3D sample_square() {
			return Vec3D(random_double() - 0.5, random_double() - 0.5, 0);
		}
		Color rayColor(Ray r, Hittable &obj, int depth) {
			Hit_record rec;
			if(depth > max_depth) {
				return Color(0, 0, 0);
			}
			if(obj.hit(r, Interval(0.01, infinity), rec) ) {
				Ray scattered;
				Color attenuation;
				if(rec.mat->scatter(r, rec, attenuation, scattered)) {
					return scale(attenuation, rayColor(scattered, obj, depth+1));
				}
				return Color(0, 0, 0); // no scattering function for the material
			}
			Vec3D direc = unit(r.d);
			double a = 0.5*(direc.y + 1);
			return Color(1, 1, 1);
			// return (1-a)*Color(1, 1, 1) + a*Color(0.5, 0.7, 1);
		}
};

#endif
