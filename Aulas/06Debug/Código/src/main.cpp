#include <iostream>
#include <cmath>
using namespace std;

int fatorial(int n);
double series(double x, int n);

int main() {
    cout << pow(2, 0) / fatorial(0) << endl;
    cout << pow(2, 1) / fatorial(0) << endl;
    cout << pow(2, 2) / fatorial(0) << endl;
    cout << pow(2, 3)  << endl;
    return 0;
}

int fatorial(int n) {
  int fat = 1;
  for (int i = 1; i <= n; i++)
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


