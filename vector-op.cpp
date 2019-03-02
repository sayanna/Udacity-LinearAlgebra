#include <iostream>
#include "vector-op.hpp"
#include <math.h>

std::vector<double> addVectors(const std::vector<double> &v1, const std::vector<double> &v2) {
	int sz1 = v1.size();
	int sz2 = v2.size();

	if (!sz1)       { return std::vector<double>(); }
	if (sz1 != sz2) { return std::vector<double>(); }
	std::vector<double> result(sz1,0);

	for (int i=0; i<sz1; ++i) {
		result[i] = v1[i]+v2[i];
	}

	return result;
}

std::vector<double> substractVectors(const std::vector<double> &v1, const std::vector<double> &v2) {
	int sz1 = v1.size();
	int sz2 = v2.size();

	if (!sz1)       { return std::vector<double>(); }
	if (sz1 != sz2) { return std::vector<double>(); }
	std::vector<double> result(sz1,0);

	for (int i=0; i<sz1; ++i) {
		result[i] = v1[i]-v2[i];
	}

	return result;
}

std::vector<double> scaleVector(const std::vector<double> &v, const double scalar) {
	int sz = v.size();

	if (!sz) { return std::vector<double>(); }
	std::vector<double> result(sz,0);

	for (int i=0; i<sz; ++i) {
		result[i] = v[i]*scalar;
	}

	return result;
}

double computeVectorMagnitude(const std::vector<double> &v) {
	int sz = v.size();

	if (!sz) { return 0; }
	double result = 0;

	for (int i=0; i<sz; ++i) {
		result += (v[i]*v[i]);
	}

	return sqrt(result);
}

std::vector<double> normalizeVector(const std::vector<double> &v) {
	int sz = v.size();
	double mag = computeVectorMagnitude(v);

	if (!sz || !mag) { return std::vector<double>(); }
	std::vector<double> result(sz);

	for (int i = 0; i < sz; ++i) {
		result[i] = (v[i]/mag);
	}

	return result;
}

double computeDotProduct(const std::vector<double> &v1, const std::vector<double> &v2) {
	int sz1 = v1.size();
	int sz2 = v2.size();

	if (sz1 != sz2) { return -1; }
	if (sz1 == 0)   { return 0; }

	double result = 0;
	for (int i = 0; i < sz1; ++i) {
		result += (v1[i] * v2[i]);
	}

	return result;
}

double computeAngleRad(const std::vector<double> &v1, const std::vector<double> &v2) {
	int sz1 = v1.size();
	int sz2 = v2.size();

	if (sz1 != sz2) { return -1; }
	if (sz1 == 0)   { return 0; }

	double mag1 = computeVectorMagnitude(v1);
	double mag2 = computeVectorMagnitude(v2);
	double dotProd = computeDotProduct(v1,v2);

	return ((mag1 && mag2) ? acos(dotProd/(mag1*mag2)) : 0);
}

double computeAngleDeg(const std::vector<double> &v1, const std::vector<double> &v2) {
	int sz1 = v1.size();
	int sz2 = v2.size();

	if (sz1 != sz2) { return -1; }
	if (sz1 == 0)   { return 0; }

	static const double pi = 3.14159;
	double angle = computeAngleRad(v1,v2);

	return ((180*angle)/pi);
}

bool checkParallel(const std::vector<double> &v1, const std::vector<double> &v2) {
	int sz1 = v1.size();
	int sz2 = v2.size();

	if (sz1 != sz2) { return false; }
	if (sz1 == 0)   { return false; }

	double mag1 = computeVectorMagnitude(v1);
	double mag2 = computeVectorMagnitude(v2);
	double dotProd = computeDotProduct(v1,v2);

	return (abs(dotProd) == abs(mag1*mag2));
}

bool checkOrthogonal(const std::vector<double> &v1, const std::vector<double> &v2) {
	int sz1 = v1.size();
	int sz2 = v2.size();

	if (sz1 != sz2) { return false; }
	if (sz1 == 0)   { return false; }

	return (computeDotProduct(v1,v2) == 0);
}

std::vector<double> computeParallelProjection(const std::vector<double> &v, const std::vector<double> &base) {
	int sz1 = v.size();
	int sz2 = base.size();
	std::vector<double> result;

	if (sz1 != sz2) { return result; }
	if (!sz1)       { return result; }

	/* parallel projection magnitude vParlMag = vMag * cos(angle)
	   dotProd(v,base) = vMag * baseMag * cos(angle)
	   vParlMag = vMag (dotProd(v,base)/(vMag*baseMag));
	   vParlMag = dorProd(v,base)/baseMag = dotProd(v,base/baseMag) = dorProd(v,NormalizedBase);
	   vPral = vPralMag * NormalizedBase = dotProd(v,NormalizedBase) * NormalizedBase;
	 */
	std::vector<double> normalizedBase = normalizeVector(base);
	double dotProd = computeDotProduct(v,normalizedBase);

	return scaleVector(normalizedBase,dotProd);
}

std::vector<double> computeOrthogonalProjection(const std::vector<double> &v, const std::vector<double> &base) {
	int sz1 = v.size();
	int sz2 = base.size();
	std::vector<double> result;

	if (sz1 != sz2) { return result; }
	if (!sz1)       { return result; }

	/* v = vParl + vOrth;
	   vOrth = v - vParl;
	*/

	std::vector<double> vParl = computeParallelProjection(v,base);

	return substractVectors(v,vParl);
}

void printVector(std::vector<double> v) {
	int sz = v.size();
	int sz1 = sz-1;

	if (!sz) { return; }

	std::cout << "[";
	for (int i=0; i<sz; ++i) {
		std::cout << v[i];

		if (i < sz1) { std::cout << ","; }
	}
	std::cout << "]" << std::endl;
}
