#include <iostream>
using namespace std;

int findMax(int *array, int len) {
  int max = -1;
  for(int i=1; i < len; i++) {
    if(max < array[i]) {
      max = array[i];
    }
  }
  return max;
}

int main() {
  int arr[5] = {60, 17, 21, 44, 2};

  int max = findMax(arr, 5);
  cout << "Valor maximo e: " << max;

  return 0;
}

