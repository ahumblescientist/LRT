#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H


#include "hittable.h"
#include <vector>
#include <memory>

using std::shared_ptr;

class Hittable_list {
	public:
		std::vector<shared_ptr<Hittable>> objects;
		Hittable_list() {}
		Hittable_list(shared_ptr<Hittable> obj) {add(obj);}
		void clear() {objects.clear();}
		void add(shared_ptr<Hittable> obj) {
			objects.push_back(obj);
		}
		bool hit(Ray &r, double tmin, double tmax, Hit_record &rec) {
			Hit_record temp_record;
			bool hit_anything = false;
			double closest = tmax;
			for(int i=0;i<objects.size();i++) {
				if(objects[i]->hit(r, tmin, tmax, temp_record)) {
					if(temp_record.t < closest) {
						hit_anything = true;
						closest = temp_record.t;
						rec = temp_record;
					}
				}
			}
			return hit_anything;
		}
};

#endif
