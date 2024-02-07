#include "ola.hpp"

void hello(){
	cout << "Starting Debug Project Template ..." << endl;
}

int fatorial(int n) {
	int fat = 0;
	for (int i = 1; i < n; i++)
	fat = fat * i;
	return fat;
}
double series(double x, int n) {
	double xpow, seriesValue;
	for (int k = 1; k <= n; k++) {
	xpow = pow(x, k);
	seriesValue += xpow / fatorial(k);
	}
	return seriesValue;
}