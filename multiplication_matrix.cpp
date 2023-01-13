#include <iostream>

using namespace std;

class Matrix{
    public:
        static const int maxSize = 20;
        
        void introFeed(char mName, int* x, int* y){
            cout<<"Enter the size of matrix "<< mName <<": \n";
            cout<<"Matrix "<<mName<<"(rows) = ";
            cin>>*x;
            cout<<"Matrix "<<mName<<"(colums) = ";
            cin>>*y;
        }


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

    int mAx = 0, mAy = 0, mBx = 0, mBy = 0;

    int matrixA[matrixObject.maxSize][matrixObject.maxSize];
    int matrixB[matrixObject.maxSize][matrixObject.maxSize];
    int matrixM[matrixObject.maxSize][matrixObject.maxSize];

    matrixObject.introFeed('A',&mAx,&mAy);
    matrixObject.introFeed('B',&mBx,&mBy);

    if(mAy!=mBx || mAx>matrixObject.maxSize|| mBx>matrixObject.maxSize|| mAy>matrixObject.maxSize|| mBy>matrixObject.maxSize){
        cout<<"\nMatrix sizes do not meet the requirements for multiplicaion.";
        return 0;
    }
    
    int (*ptr1)[matrixObject.maxSize] = matrixA; matrixObject.accpetMatrix(ptr1, mAx, mAy,'A');
    int (*ptr2)[matrixObject.maxSize] = matrixB; matrixObject.accpetMatrix(ptr2, mBx, mBy,'B');

    cout<<endl;

    cout<<"Matrix A: \n";
    matrixObject.printMatrix(mAx,mAy,matrixA);
    cout<<endl;

    cout<<"Matrix B: \n";
    matrixObject.printMatrix(mBx,mBy,matrixB);
    cout<<endl;
    
    for(int k = 0; k < mAx; k++){
        for(int j = 0; j < mBy; j++){
            int temp = 0;
            for (int i = 0; i < mBx; i++) {
                temp = temp + matrixA[k][i]*matrixB[i][j];
            }
            matrixM[k][j] = temp;
        }
    }

    cout<<"Multiplication of Matrix A and Matrix B: \n";
    matrixObject.printMatrix(mAx,mBy,matrixM);
    cout<<endl;

    return 0;
}