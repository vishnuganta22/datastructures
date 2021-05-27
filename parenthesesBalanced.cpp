#include <iostream>
#include <string>

using namespace std;

struct Node{
    char data;
    Node* next;
};

class Stack{
    private:
        Node* top;
    public:
        void push(char data){
            Node* temp = new Node();
            temp->data = data;
            temp->next = NULL;

            if(top != NULL){
                temp->next = top;
            }
            top = temp;
        }

        char pop(){
            Node *temp = top;
            char data = temp->data;
            top = temp->next;
            delete temp;
            return data;
        }

        char getTop(){
            if(top == NULL) return -1;
            return top->data;
        }

        bool isEmpty(){
            return top == NULL;
        }        
};

int contains(char* list, int listLength, char input){
    for(int i=0; i < listLength; i++){
        if(input == list[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    char list[] = {'{', '}', '[', ']', '(', ')', '<', '>'};
    char openList[] = {'{', '[', '(', '<'};
    char closeList[] = {'}', ']', ')', '>'};
    char* input = new char[500];
    cout<<"Enter a string to check whether it is a Balanced Parentheses or not :: "<< endl;
    cin.getline(input, 500);
    int length = strlen(input);

    bool isBalanced = true;
    Stack* stack = new Stack();
    for(int i=0; i < length; i++){
        if(contains(list, 8, input[i]) >= 0){
            if(contains(openList, 4, input[i]) >=0){
                stack->push(input[i]);
            }else {
                int position = contains(closeList, 4, input[i]);
                if(position >=0 && stack->getTop() == openList[position]){
                    stack->pop();
                }else{
                    isBalanced = false;
                    break;
                }
            }
        }
    }


    if(!stack->isEmpty()){
       isBalanced = false; 
    }

    if(isBalanced){
        cout<<"Input is Balanced"<<endl;
    }else{
        cout<<"Input is Not Balanced"<<endl;
    }
}