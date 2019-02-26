#pragma once

typedef struct {
	double x;
	double y;
	mathVector():x(0),y(0){};
} mathVector;

mathVector addVectors(mathVector v1, mathVector v2);
mathVector substractVectors(mathVector v1, mathVector v2);
mathVector scaleVector(mathVector v, double scalar);
