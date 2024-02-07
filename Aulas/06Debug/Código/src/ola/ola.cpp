#include "ola.hpp"

void hello(){
	cout << "Starting Debug Project Template ..." << endl;
	cout << "The commented codes into ola.hpp contract have problems. Can you correct them?" << endl;
	cout << "Copy to the main program and good luck!" << endl;
}

/*----------------------------EXEMPLO_01-----------------------------------
#include <iostream>
#include <cmath>
using namespace std;

double series(double x, int n);
int fatorial(int n);

int main(){
	cout << series(2, 3) << endl;
	return 0;
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
-------------------------------------------------------------------------
----------------------------EXEMPLO_02-----------------------------------

int main() {
	int arr[5] = {17, 21, 44, 2, 60};
	int max;
	if (findMax(arr, 5, max) != 0) {
		cout << "Ocorreu erro!" << endl;
		exit(1);
	}
	cout << "Valor maximo e: " << max << endl;
	return 0;
} 

int findMax(int *array, int len, int max) {
	max = array[0];
	for(int i=1; i <= len; i++) {
		if(max < array[i]) {
			max = array[i];
		}
	}
	return 0;
}

---------------------------------------------------------------------------*/