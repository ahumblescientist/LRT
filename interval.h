#ifndef INTERVAL_H
#define INTERVAL_H

#include "constants.h"

class Interval {
	public:
		double min, max;
		Interval() : min(infinity), max(-infinity) {}
		Interval(double mi, double ma) : min(mi), max(ma) {}
		double size() {
			return max - min;
		}
		bool contains(double v) {
			return min <= v && v <= max;
		}
		bool surrounds(double v) {
			return min < v && v < max;
		}
		static const Interval Empty, Universe;
};
const Interval Interval::Empty = Interval();
const Interval Interval::Universe = Interval(-infinity, infinity);


#endif
