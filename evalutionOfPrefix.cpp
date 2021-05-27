#include <iostream>
#include <ctype.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
        Node* top;
        int size;
    public:
        void push(int data){
            Node* temp = new Node();
            temp->data = data;
            temp->next = NULL;

            if(top != NULL){
                temp->next = top;
            }
            top = temp;
            size++;
        }

        int pop(){
            Node *temp = top;
            char data = temp->data;
            top = temp->next;
            delete temp;
            size--;
            return data;
        }

        int getTop(){
            if(top == NULL) return -1;
            return top->data;
        }

        bool isEmpty(){
            return top == NULL;
        }  

        int getSize(){
            return size;
        }      
};

bool contains(char* operators, int size, char c){
    for(int i = 0; i < size; i++){
        if(operators[i] == c){
            return true;
        }
    }
    return false;
}

int main(){
    char operators[] = {'+', '-', '/', '*', '^'};
    char* input = new char[500];
    cout<<"Enter a PreFix Expression for Evalution "<< endl;
    cin.getline(input, 500);
    int length = strlen(input);

    Stack* stack = new Stack();
    Stack* operandStack = new Stack();
    for(int i=length-1; i >= 0; i--){
        if(isspace(input[i])){
            if(!operandStack->isEmpty()){
                int operand = 0;
                while (!operandStack->isEmpty())
                {
                    operand = (operand * 10) + operandStack->pop();
                }
                stack->push(operand);
            }
            delete operandStack;
            operandStack = new Stack();
            continue;
        } 
        if(contains(operators, 5, input[i])){
            if((stack->isEmpty() || stack->getSize() < 2)){
                cout<<"Invalid PreFix Expression "<<endl;
                return 0;
            }else{
                int a = stack->pop();
                int b = stack->pop();
                int r;
                switch (input[i])
                {
                    case '+':
                        r = a+b;
                        stack->push(r);
                        break;
                    case '-':
                        r = a-b;
                        stack->push(r);
                        break;
                    case '*':
                        r = a*b;
                        stack->push(r);
                        break;
                    case '/':
                        r = a/b;
                        stack->push(r);
                        break;
                    case '^':
                        r = a^b;
                        stack->push(r);
                        break;                
                }  
            }
        }else{
            operandStack->push(input[i] - '0');
        }
    }

    int size = stack->getSize();
    if(size > 1){
        cout<<"Invalid PreFix Expression "<<endl;
    }else{
        cout<<"value after evalution of PreFixExpression :: "<<stack->getTop()<<endl;
    }
}