#include <iostream>

using namespace std;

class Stack{

    private:
        int top;
        int size;
        int* array;

    public:

    Stack(int cap){
        this->size =  cap;
        this->top = -1;
        this->array = new int[size];
    }

    void push(int value){
        if(this->top == this->size - 1) {
            cout<<"Error: stack overflow"<<endl;
        }
        else{
            this->top++;
            this->array[this->top] = value;
        }
    }

    int pop(){
        if(this->top == -1) {
            cout << "Error: stack underflow"<<endl;
            return INT_MIN;
        }
        int value = this->array[this->top];
        this->top--;
        return value;
    }

    int peek(){
        if(this->top == -1) {
            cout << "Error: stack is empty"<<endl;
            return INT_MIN; 
        }
        return this->array[this->top];
    }

    bool isEmpty() {
        return (this->top == -1);
    }

    bool isFull() {
        return (this->top == this->size - 1);
    }
};

int main(){
    
    Stack stack(5);

    stack.push(158);
    stack.push(237);
    stack.push(350);
    stack.push(425);
    stack.push(509);

    cout<<"Is Empty: "<<stack.isEmpty()<<endl;
    cout<<"Is Full: "<<stack.isFull()<<endl;
    
    cout<<"Popping: "<<stack.pop()<<endl;

    cout<<"Is Empty: "<<stack.isEmpty()<<endl;
    cout<<"Is Full: "<<stack.isFull()<<endl;

    cout<<"Peek: "<<stack.peek();cout<<endl;

    while (!stack.isEmpty()) {
        cout<<"Popped: "<<stack.pop()<<endl;
    }

    cout<<"Is Empty: "<<stack.isEmpty()<<endl;
    cout<<"Is Full: "<<stack.isFull();

    return 0;
}
