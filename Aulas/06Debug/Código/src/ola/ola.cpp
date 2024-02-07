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
int findMax(int *array, int len) {
  int max = -1;
  for(int i=1; i <= len; i++) {
    if(max < array[i]) {
      max = array[i];
    }
  }
  return 0;
}

int main() {
  int arr[5] = {60, 17, 21, 44, 2};

  int max = findMax(arr, 5);
  cout << "Valor maximo e: " << max;

  return 0;
}
---------------------------------------------------------------------------*/