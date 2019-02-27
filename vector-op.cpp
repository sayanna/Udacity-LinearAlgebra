#include "vector-op.hpp"

mathVector addVectors(const mathVector v1, const mathVector v2) {
	mathVector result;
	result.x = v1.x+v2.x;
	result.y = v1.y+v2.y;
	result.z = v1.z+v2.z;

	return result;
}

mathVector substractVectors(const mathVector v1, const mathVector v2) {
	mathVector result;
	result.x = v1.x-v2.x;
	result.y = v1.y-v2.y;
	result.y = v1.z-v2.z;

	return result;
}

mathVector scaleVector(const mathVector v, const double scalar) {
	mathVector result;
	result.x = (v.x*scalar);
	result.y = (v.y*scalar);
	result.z = (v.z*scalar);

	return result;
}
