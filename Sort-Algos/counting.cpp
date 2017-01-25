#include <iostream>

using namespace std;

int main(){

    int* arr;
    int* sorted_Arr;
    int* counter_Arr;
    int l;
    int max;
    cout << "Write the number of elements to be sorted: ";
    cin >> l;
    arr = new int[l];
    sorted_Arr = new int[l];
    cout << "Array: ";
    for (int i = 0; i < l; i++) {
        cin >> arr[i];
    }
    cout << "Max element is: ";
    cin >> max;
    counter_Arr = new int[max+1];
    for (int i = 0; i < max+1; i++) {
        counter_Arr[i] = 0;
    }
    for (int i = 0; i < l; i++) {
        counter_Arr[arr[i]]++;
    }
    for (int i = 0; i < max; i++) {
        counter_Arr[i+1] += counter_Arr[i];
    }

    for (int i = l-1; i >= 0; i--) {
        counter_Arr[arr[i]]--;
        sorted_Arr[counter_Arr[arr[i]]] = arr[i];
    }

    for(int i=0;i<l;i++){
        cout << sorted_Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
