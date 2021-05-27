# include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    void push(int data){
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;

        if(top != NULL){
            temp->next = top;
        }
        top = temp;
    }

    int pop(){
        Node *temp = top;
        int data = temp->data;
        top = temp->next;
        delete temp;
        return data;
    }

    int getTop(){
        if(top == NULL) return -1;
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }        
};

int main(){
    Stack* stack = new Stack();
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