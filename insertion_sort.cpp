#include <iostream>

using namespace std;

class Sort{
    public:

        void swapVal(double *var1, double *var2){
            double temp = *var2;
            *var2 = *var1;
            *var1 = temp;
        }
        
        void printArray(double *array, int arSize){
            for (int i = 0; i < arSize; i++){
                cout <<array[i]<<"|";
            }
        }

        void sortArray(double* array,int arSize){
            int j = 1;
            for(int i = 1; i < arSize; i++){
                int k = i;

                while(array[k]<array[k-1]){
                    double* p1 = &array[k];
                    double* p2 = &array[k-1];
                    swapVal(p1,p2);
                    if(k!=0){
                        k--;
                    }
                    cout<<"Iteration "<<j<<": "; j++;
                    printArray(array,arSize);
                    cout<<endl;
                }
                
            }
        }

};

int main(){

    Sort sort;

    double arr[] = {58,74,23,2,90,88};
    int sizeArr = 6;
    double sortArr[sizeArr];

    for(int i = 0; i < sizeArr; i++ ){
        sortArr[i] = arr[i];
    }

    cout<<"Array given by the user: ";
    sort.printArray(sortArr,sizeArr);
    cout<<endl; cout<<endl;

    sort.sortArray(sortArr,sizeArr);
    
    cout<<"\nFinal array sorted by Insertion Sort Method: ";
    sort.printArray(sortArr,sizeArr);

    return 0;
}