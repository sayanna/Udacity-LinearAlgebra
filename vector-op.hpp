#pragma once

typedef struct _mathVector{
	double x;
	double y;
	double z;
	_mathVector():x(0),y(0){};
	_mathVector(double a, double b):x(a),y(b),z(0){};
	_mathVector(double a, double b, double c):x(a),y(b),z(c){};
} mathVector;

mathVector addVectors(mathVector v1, mathVector v2);
mathVector substractVectors(mathVector v1, mathVector v2);
mathVector scaleVector(mathVector v, double scalar);
