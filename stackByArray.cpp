#include <iostream>

using namespace std;

class Stack{
private:
    int top;
    int *arr;
    int size;
public:
    Stack(int size){
        top=-1;
        this->size = size;
        arr = new int[this->size];
    }

    void push(int data){
        if(top == size - 1) cout<<"Stack is FULL";
        else{
            top++;
            arr[top] = data;
        }
    }

    int pop(){
        if(top == -1) return -1;
        else{
            int ele = arr[top];
            top--;
            return ele;
        }
    }

    int getTop(){
        if(top == -1) return -1;
        else return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }    
};

int main(){
    Stack* stack = new Stack(10);
    cout<<"Is Stack Empty :: " << stack->isEmpty()<<endl;
    stack->push(2);
    stack->push(1);
    stack->push(9);
    stack->push(4);
    cout<<"Is Stack Empty :: " << stack->isEmpty()<<endl;
    cout<<"Stack Top :: "<<stack->getTop()<<endl;
    cout<<"Removed :: "<<stack->pop()<<endl;
    stack->push(5);
    cout<<"Stack Top :: "<<stack->getTop()<<endl;
}