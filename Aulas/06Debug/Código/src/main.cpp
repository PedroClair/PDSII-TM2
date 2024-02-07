#include<iostream>
using namespace std;

int findMaxCor(int *array, int len, int max);

int main() {
    int arr[5] = {17, 21, 44, 2, 60};
    int max;
    if (findMaxCor(arr, 5, max) != 0) {
        cout << "Ocorreu erro!" << endl;
        exit(1);
    }
    cout << "Valor maximo e: " << max << endl;
    return 0;
}

int findMaxCor(int *array, int len, int max) {
	max = array[0];
	for(int i=1; i <= len; i++) {
		if(max < array[i]) {
			max = array[i];
		}
	}
	return 0;
}