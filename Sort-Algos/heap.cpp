#include <iostream>

using namespace std;

int main(){

    int* arr;
    int* heap_Arr;
    int l;
    cout << "Write the number of elements to be sorted: ";
    cin >> l;
    arr = new int[l];
    heap_Arr = new int[l+1];
    cout << "Array: ";
    for (int i = 1; i < l+1; i++) {
        int tmp = 0;
        cin >> tmp;
        heap_Arr[i] = tmp;

        for (int j = i; j > 1 && heap_Arr[j/2] < heap_Arr[j]; j++) {
            heap_Arr[j] = heap_Arr[j/2];
            heap_Arr[j/2] = tmp;
        }
    }
    cout << "heap: ";
    for (int i = 1; i <= l; ++i) {
        cout << heap_Arr[i] << " ";
    }
    cout << endl;
    for (int i = l-1; i >= 0; i--) {
        arr[i] = heap_Arr[1];
        heap_Arr[1] = heap_Arr[i+1];

        for (int j = 1;j < i-1;) {
            if(heap_Arr[j] < heap_Arr[2*j]){
                int tmp = heap_Arr[j];
                heap_Arr[j] = heap_Arr[2*j];
                heap_Arr[2*j] = tmp;
                j = 2*j;
            }
            else if(heap_Arr[j] < heap_Arr[2*j + 1]){
                int tmp = heap_Arr[j];
                heap_Arr[j] = heap_Arr[2*j + 1];
                heap_Arr[2*j + 1] = tmp;
                j = 2*j + 1;
            }
            else{
                break;
            }
        }
        cout << "heap: ";
        for (int i = 1; i <= l; ++i) {
            cout << heap_Arr[i] << " ";
        }
        cout << endl;
    }
    arr[0] = heap_Arr[2];
    cout << endl;
    for (int i = 0; i < l; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;



}
