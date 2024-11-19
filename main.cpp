#include <iostream>
#include <fstream>
#include "color.h"
#include "vec.h"
#include "ray.h"

#define ASPECT_RATIO 1.6 // 1600:1000

bool hit_sphere(Point3D center, double radius, Ray &r) {
	Vec3D Q = center - r.origin;
	double a = r.d * r.d;
	double b = -2 * Q * r.d;
	double c = Q * Q - radius * radius;
	if(b*b - 4*a*c < 0) {
		return false;
	}
	return true;
}

Color rayColor(Ray &r) {
	Vec3D unitDirection = normal(r.d);
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


	output << "P3\n" << " " << image_width << " " << image_height << "\n255\n";
	for(int i=0;i<image_height;i++) {
		for(int j=0;j<image_width;j++) {
			Color color;
			Vec3D location = pixel0 + j * deltaU + i * deltaV;
			Vec3D direction = location - cameraCenter;
			Ray r(cameraCenter, direction);
			if(hit_sphere(Point3D(0, 0, -2), 1, r)) {
				color = rayColor(r);
			} else {
				color = Color(1, 1, 1);
			}
			writeColor(output, color);
		}
	}

	output.close();
	return 0;
}
