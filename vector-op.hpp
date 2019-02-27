#pragma once

typedef struct _mathVector{
	double x;
	double y;
	_mathVector():x(0),y(0){};
	_mathVector(double a, double b):x(a),y(b){};
} mathVector;

mathVector addVectors(mathVector v1, mathVector v2);
mathVector substractVectors(mathVector v1, mathVector v2);
mathVector scaleVector(mathVector v, double scalar);
