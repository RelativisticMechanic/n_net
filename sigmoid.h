#ifndef SIGMOID_H
#define SIGMOID_H

#include <cmath>

inline double sigmoid(double x) {
	//sigmoid(x) = 1/1+e^(-x)
	return (1/(1+exp(-x)));
}

inline double frand(void) {
	double frac_x = (double)rand()/RAND_MAX;
	double GIF_x = rand();
	return GIF_x + frac_x;
}
#endif
