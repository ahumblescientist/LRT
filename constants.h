#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <limits>
#include <memory>
#include <iostream>
#include <cmath>

using std::make_shared;
using std::shared_ptr;

const double pi = 3.1415926535;
const double infinity = std::numeric_limits<double>::infinity();

#define degrees_to_radians(deg) (pi / (180.0l) * (double) deg)

#include "vec.h"
#include "color.h"
#include "ray.h"

#endif
