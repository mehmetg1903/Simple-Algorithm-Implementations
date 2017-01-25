#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int* arr1;
    int* arr2;
    int counter[10];
    int l,dig;
    cout << "Write the number of elements to be sorted: ";
    cin >> l;
    arr1 = new int[l];
    arr2 = new int[l];
    cout << "Array: ";
    for (int i = 0; i < l; i++) {
        cin >> arr1[i];
    }
    cout << "Max number of digits: ";
    cin >> dig;

    for (int i = 1; i <= dig; i++) {
        cout << "i: " << i << endl;
        for (int j = 0; j < 10; j++) {
            counter[j] = 0;
        }
        for (int j = 0; j < l; j++) {
            counter[(arr1[j] % ((int)(pow(10,i)))) / ((int)(pow(10,i-1)))]++;
        }
        for (int j = 1; j < 10; j++) {
            counter[j] += counter[j-1];
        }
        for (int j = 0; j < 10; j++) {
            cout << counter[j] << " ";
        }
        cout << endl;
        for (int k = l-1; k >= 0; k--){
            arr2[counter[(arr1[k] % ((int)(pow(10,i)))) / ((int)(pow(10,i-1)))] - 1] = arr1[k];
            counter[(arr1[k] % ((int)(pow(10,i)))) / ((int)(pow(10,i-1)))]--;

        }

        copy(arr2,arr2+l,arr1);
        for (int i = 0; i < l; ++i) {
            cout << arr1[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
