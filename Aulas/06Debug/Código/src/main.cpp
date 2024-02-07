#include "ola.hpp"

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