#include <iostream>

using namespace std;

class Queue{
    private:
        int front,rear,size;
        int* array;

    public:
        Queue(int cap){
            size =  cap;
            front = -1;
            rear = -1;
            array = new int[size];
        }

        bool isFull() {
            if (front == 0 && rear == size - 1) {
                return true;
            }
            return false;
        }

        bool isEmpty() {
            if (front == -1){
                return true;
            }
            return false;
        }

        void enQueue(int val) {
            if (isFull()) {
                cout<<"Queue is full";
            } 
            else {
                if (front == -1) {front = 0;}
                rear++;
                array[rear] = val;
                cout<<endl<<"Inserted "<<val<<endl;
            }
        }

        int deQueue() {
            int val;
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return (-1);
            } 
            val = array[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }
            cout<<endl<< "Deleted -> " <<val<<endl;
            return val;
        }
};

int main(){

    Queue queue(3);
    
    queue.enQueue(101);
    queue.enQueue(202);
    queue.enQueue(303);

    cout<<"Is Empty: "<<queue.isEmpty()<<endl;
    cout<<"Is Full: "<<queue.isFull()<<endl;

    queue.deQueue();

    cout<<"Is Empty: "<<queue.isEmpty()<<endl;
    cout<<"Is Full: "<<queue.isFull()<<endl;

    while (!queue.isEmpty()) {
        queue.deQueue();
    }

    cout<<"Is Empty: "<<queue.isEmpty()<<endl;
    cout<<"Is Full: "<<queue.isFull()<<endl;

    return 0;
}
