#include <iostream>

#include <vector>
using namespace std;

int main(){
	int num = 0;
	cout << "Enter the numbers that will be sorted.\n";
	cout << "Enter -1 to end.\n";
	vector <int> a;
	while(num != -1) {
		cin >> num >> ws;
		a.push_back(num);
	}
    int size=a.size();
    int gap, i, j, t;
    for (gap = size; gap /= 2;) {
        for (i = gap; i < size; i++) {
            t = a[i];
            for (j = i; j >= gap && t < a[j - gap]; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = t;
        }
    }
	
	cout << "Sorted array:/t";
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
