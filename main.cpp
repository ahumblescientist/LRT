#include <fstream>
#include "constants.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

int main() {
	Hittable_list world;
	world.add(make_shared<Sphere>(0.5, Point3D(0, 0, -1)));
	world.add(make_shared<Sphere>(100, Point3D(0, -100.5, -1)));
	Camera cam;
	cam.aspect_ratio = 16.0l / 9.0l;
	cam.image_width = 400;
	cam.render(world);
	return 0;
}
