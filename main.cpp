#include <fstream>
#include "constants.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

#define ASPECT_RATIO 1.6 // 1600:1000

Color rayColor(Ray &r, Hittable_list &world) {
	Hit_record rec;
	if(world.hit(r, Interval(0, infinity), rec)) {
		return 0.5*(rec.normal + Color(1, 1, 1));
	}
	Vec3D unitDirection = unit(r.d);
	double a = 0.5*(unitDirection.y + 1.0l);
	return (1-a) * Color(1, 1, 1) + a * Color(0.5, 0.7, 1.0f);
}

int main() {
	int image_width = 256;
	int image_height = float(image_width) / ASPECT_RATIO;
	float viewport_height = 2.0f;
	float viewport_width = viewport_height * (float)(image_width)/(float)(image_height);
	float focal_length = 1.0f;
	Point3D cameraCenter = Point3D(0, 0, 0);

	Vec3D viewportU = Vec3D(viewport_width, 0, 0);
	Vec3D viewportV = Vec3D(0, -viewport_height, 0);

	Vec3D deltaU = viewportU/image_width;
	Vec3D deltaV = viewportV/image_height;
	Vec3D start = -viewportV/2 - viewportU/2 + cameraCenter - Vec3D(0, 0, focal_length); // - focal_length because the scene is rendered at -Z
	Vec3D pixel0 = start + (deltaV + deltaU) / 2;
	std::ofstream output("out.ppm");

	Hittable_list world;
	world.add(make_shared<Sphere>(0.5, Point3D(0, 0, -1)));
	world.add(make_shared<Sphere>(100, Point3D(0, -100.5, -1)));
	output << "P3\n" << " " << image_width << " " << image_height << "\n255\n";
	for(int i=0;i<image_height;i++) {
		for(int j=0;j<image_width;j++) {
			Color color;
			Vec3D location = pixel0 + j * deltaU + i * deltaV;
			Vec3D direction = location - cameraCenter;
			Ray r(cameraCenter, direction);
			color = rayColor(r, world);
			writeColor(output, color);
		}
	}

	output.close();
	return 0;
}
