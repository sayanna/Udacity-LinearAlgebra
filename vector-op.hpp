#pragma once
#include <vector>

void printVector(std::vector<double> v);
std::vector<double> addVectors(const std::vector<double> &v1, const std::vector<double> &v2);
std::vector<double> substractVectors(const std::vector<double> &v1, const std::vector<double> &v2);
std::vector<double> scaleVector(const std::vector<double> &v, const double scalar);
double computeVectorMagnitude(const std::vector<double> &v);
std::vector<double> normalizeVector(const std::vector<double> &v);
double computeDotProduct(const std::vector<double> &v1, const std::vector<double> &v2);
double computeAngleRad(const std::vector<double> &v1, const std::vector<double> &v2);
double computeAngleDeg(const std::vector<double> &v1, const std::vector<double> &v2);
bool checkParallel(const std::vector<double> &v1, const std::vector<double> &v2);
bool checkOrthogonal(const std::vector<double> &v1, const std::vector<double> &v2);
std::vector<double> computeParallelProjection(const std::vector<double> &v, const std::vector<double> &base);
std::vector<double> computeOrthogonalProjection(const std::vector<double> &v, const std::vector<double> &base);
