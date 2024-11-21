#include <fstream>
#include "constants.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

int main() {
	Hittable_list world;
	shared_ptr<Metal> mirror = make_shared<Metal>(Color(0.8, 0.8, 0.8));
	shared_ptr<Lambertian> lamb = make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
	shared_ptr<Lambertian> lamb_red = make_shared<Lambertian>(Color(0.8, 0.2, 0.0));
	world.add(make_shared<Sphere>(0.5, Point3D(-1, 0, -1), mirror));
	world.add(make_shared<Sphere>(100, Point3D(0, -100.5, -1), lamb));
	world.add(make_shared<Sphere>(0.1, Point3D(0, 0, -1), lamb_red));
	world.add(make_shared<Sphere>(0.5, Point3D(2, 0, -0.60001), lamb_red));
	Camera cam;
	cam.aspect_ratio = 16.0l / 9.0l;
	cam.image_width = 1600;
	cam.render(world);
	return 0;
}
