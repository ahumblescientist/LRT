#include <iostream>
#include <fstream>
#include "color.h"
#include "vec.h"

int main() {
	int image_width = 256;
	int image_height = 256;
	std::ofstream output("out.ppm");


	output << "P3\n" << " " << image_width << " " << image_height << "\n255\n";
	for(int i=0;i<image_height;i++) {
		for(int j=0;j<image_width;j++) {
			Color color;
			if(i == j || (image_width - j) == i || (j == 128) || (i == 128)) {
				color = Color(1, 0, 0);
			} else {
				color = Color(0, 0, 0);
			}
			writeColor(output, color);
		}
	}

	output.close();
	return 0;
}
