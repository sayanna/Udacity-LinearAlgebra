#include "vector-op.hpp"

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

std::vector<double> substractVectors(const std::vector<double> v1, const std::vector<double> v2) {
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

std::vector<double> scaleVector(const std::vector<double> v, const double scalar) {
	int sz = v.size();

	if (!sz) { return std::vector<double>(); }
	std::vector<double> result(sz,0);

	for (int i=0; i<sz; ++i) {
		result[i] = v[i]*scalar;
	}

	return result;
}

void printVector(std::vector<double> v) {
	int sz = v.size();

	if (!sz) { return; }

	for (auto e : v) {
		std::cout << e << ",";
	}
	std::cout << std::endl;
}
