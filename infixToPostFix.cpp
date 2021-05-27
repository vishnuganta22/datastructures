#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

struct Node{
    char data;
    Node* next;
};

struct LinkedListNode
{
    char data;
    LinkedListNode *link;
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


class LinkedList
{
    private:
        LinkedListNode *head;

        void printInReverse(LinkedListNode* node){
            if(node == NULL){
                return;
            }
            printInReverse(node->link);
            cout << node->data;
        }

    public:
        LinkedList()
        {
            this->head = NULL;
        }

        void insert(char digit)
        {
            LinkedListNode *temp = new LinkedListNode();
            temp->data = digit;
            if (head != NULL) temp->link = head;
            head = temp;
        }

        void printAll()
        {
            LinkedListNode *temp = head;
            while (temp->link != NULL)
            {
                cout << temp->data;
                temp = temp->link;
            }
            cout << temp->data << endl;
        }

        void printInReverse(){
            printInReverse(head);
            cout<<endl;
        }
};

bool contains(char* list, int length, char c){
    for(int i=0; i<length; i++){
        if(list[i] == c) return true;
    }
    return false;
}

bool isEqualOrHigh(char first, char second){
    if(first == '^'){
        return true;
    }else if((first == '/' || first == '*') && (second == '/' || second == '*' || second == '+' || second == '-')){
        return true;
    }else if((first == '+' || first == '-') && (second == '-' || second == '+')){
        return true;
    }
    return false;
}

int main(){
    char* input = new char[500];
    cout<<"Enter Infix expression to convert to postfix :: "<<endl;
    cin.getline(input, 500);
    int length = strlen(input);
    char operators[] = {'^', '/', '*', '+', '-'};

    LinkedList* list = new LinkedList();
    Stack* stack = new Stack();
    bool shouldAddSpace = false; 
    for(int i = 0; i < length; i++){
        if(contains(operators, 5, input[i])){
            if(isEqualOrHigh(stack->getTop(), input[i])){
                while (!stack->isEmpty() && isEqualOrHigh(stack->getTop(), input[i]))
                {
                    list->insert(' ');
                    list->insert(stack->pop());
                }
                stack->push(input[i]);
            }else{
                stack->push(input[i]);
            }
        }else{
            if(isspace(input[i])){
                shouldAddSpace = true;
            }else{
                if(shouldAddSpace){
                    list->insert(' ');
                }
                list->insert(input[i]);
            }
        }
    }

    while (!stack->isEmpty())
    {
        list->insert(' ');
        list->insert(stack->pop());
    }
    list->printInReverse();
}