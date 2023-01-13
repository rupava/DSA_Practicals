#include <iostream>

using namespace std;

class Matrix{
    public:
        static const int maxSize = 20;
        
        void printMatrix(int rows, int cols, int array[maxSize][maxSize]) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
        }

        void accpetMatrix(int (*array)[maxSize], int x, int y, char mName){
            for(int i=0; i < x; i++){
                cout<<"\nRow No. "<< i+1 <<" for Matrix "<<mName<<": \n";
                for(int j = 0; j < y; j++){
                    cin>>array[i][j];
                }
            }
        }

};

int main(){

    Matrix matrixObject;

    int mX = 0, mY = 0;

    int matrixA[matrixObject.maxSize][matrixObject.maxSize];
    int matrixB[matrixObject.maxSize][matrixObject.maxSize];
    int matrixD[matrixObject.maxSize][matrixObject.maxSize];
    
    cout<<"Enter the size of matrix: \n";
    cout<<"Matrix Rows = ";
    cin>>mX;
    cout<<"Matrix Colums = ";
    cin>>mY;

    if(mX>matrixObject.maxSize || mY>matrixObject.maxSize){
        cout<<"\nMatrix sizes do not meet size constraints.";
        return 0;
    }
    
    int (*ptr1)[matrixObject.maxSize] = matrixA; matrixObject.accpetMatrix(ptr1, mX, mY,'A');
    int (*ptr2)[matrixObject.maxSize] = matrixB; matrixObject.accpetMatrix(ptr2, mX, mY,'B');

    cout<<endl;

    cout<<"Matrix A: \n";
    matrixObject.printMatrix(mX,mY,matrixA);
    cout<<endl;

    cout<<"Matrix B: \n";
    matrixObject.printMatrix(mX,mY,matrixB);
    cout<<endl;
    
    for(int j = 0; j < mX; j++ ){
        for(int i = 0; i < mY; i++){
            int temp = matrixA[j][i]-matrixB[j][i];
            matrixD[j][i] = temp;
        }
    }

    cout<<"Subtraction of Matrix A with Matrix B: \n";
    matrixObject.printMatrix(mX,mY,matrixD);
    cout<<endl;

    return 0;
}