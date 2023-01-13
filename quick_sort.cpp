#include <iostream>

using namespace std;

class Sort{
    public:
        void swap(int arr[] , int pos1, int pos2){
            int temp;
            temp = arr[pos1];
            arr[pos1] = arr[pos2];
            arr[pos2] = temp;
        }

        int partition(int arr[], int low, int high, int pivot){
            int i = low;
            int j = low;
            while( i <= high){
                if(arr[i] > pivot){
                    i++;
                }
                else{
                    swap(arr,i,j);
                    i++;
                    j++;
                }
            }
            return j-1;
        }

        void quickSort(int arr[], int low, int high){
            if(low < high){
            int pivot = arr[high];
            int pos = partition(arr, low, high, pivot);
            
            quickSort(arr, low, pos-1);
            quickSort(arr, pos+1, high);
            }
        }

        void display(int *array, int size) {
            for(int i = 0; i<size; i++){
                cout << array[i] << "|";
            }
            cout << endl;
        }
};

int main(){

    Sort sort;

	int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    sort.display(arr, n);
    sort.quickSort(arr, 0, n-1);
    cout << "Array after Sorting: ";
    sort.display(arr, n);

    return 0;
}