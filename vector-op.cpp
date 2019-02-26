#include "vector-op.hpp"

mathVector addVectors(const mathVector v1, const mathVector v2) {
	mathVector result;
	result.x = v1.x+v2.x;
	result.y = v1.y+v2.y;

	return result;
}

mathVector substractVectors(const mathVector v1, const mathVector v2) {
	mathVector result;
	result.x = v1.x-v2.x;
	result.y = v1.x-v2.y;

	return result;
}

mathVector scaleVector(const mathVector v, const double scalar) {
	mathVector result;
	result.x = (v.x*scalar);
	result.y = (v.y*scalar);

	return result;
}
