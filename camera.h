#ifndef CAMERA_H
#define CAMERA_H

#include "constants.h"
#include "hittable.h"
#include "hittable_list.h"

class Camera {

	public:
		double aspect_ratio = 1.6;
		int image_width = 100;
		void render(Hittable &world) {
			init();	
			std::ofstream output("out.ppm");
			output << "P3\n" << " " << image_width << " " << image_height << "\n255\n";
			for(int i=0;i<image_height;i++) {
				for(int j=0;j<image_width;j++) {
					Point3D location = pixel00 + (double(j) * deltaU) + (double(i) * deltaV);
					Vec3D direction  = location - center;
					Color color;
					Ray r(center, direction);
					color = rayColor(r, world);
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
		Color rayColor(Ray &r, Hittable &obj) {
			Hit_record rec;
			if(obj.hit(r, Interval(0, infinity), rec)) {
				return 0.5 * (rec.normal + Color(1, 1, 1));
			}
			Vec3D direc = unit(r.d);
			double a = 0.5*(direc.y + 1);
			return (1-a)*Color(1, 1, 1) + a*Color(0.5, 0.7, 1);
		}
};

#endif
