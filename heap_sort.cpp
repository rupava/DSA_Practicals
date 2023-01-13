#include <iostream>

using namespace std;

class Sort{

    public:
        void heapify(int arr[], int n, int i){
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n && arr[l] > arr[largest]){largest = l;}

            if (r < n && arr[r] > arr[largest]){largest = r;}

            if (largest != i){
                swap(arr[i], arr[largest]);
                heapify(arr, n, largest);
            }
        }

        void heapSort(int arr[], int n){
            for (int i = n / 2 - 1; i >= 0; i--){heapify(arr, n, i);}

            for (int i = n - 1; i >= 0; i--) {
                swap(arr[0], arr[i]);
                heapify(arr, i, 0);
            }
        }

        void display(int arr[], int n){
            for (int i = 0; i < n; ++i){cout << arr[i] << "|";}
            cout << "\n";
        }
};

int main(){

    Sort sort;

    int sz;
    cout << "Enter the number of elements: ";
    cin >> sz;
    int arr[sz];
    cout << "Enter elements:" << endl;
    for(int i = 0; i<sz; i++) {
        cin >> arr[i];
    }
	
    int n = sizeof(arr) / sizeof(arr[0]);
	for(int i=n/2 -1;i>=0;i--){
	    sort.heapify(arr,n,i);
    }

    cout << "After heapifying array is: "<<endl;
    sort.display(arr, n);
    sort.heapSort(arr, n);
    cout << "Sorted array is: \n";
    sort.display(arr, n);
        
    return 0;
}