#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class LinkedList{
private:
    Node* head;
    int size;

public:
    LinkedList(){
        head = NULL;
        size = 0;
    }

    void insertAtHead(int data){
        Node* temp = new Node;
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }else{
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtTail(int data){
        Node* temp = new Node;
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        
        if(head == NULL){
            head = temp;
        }else{
            Node* curr = head;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = temp;
            temp->prev = curr;
        }
        size++;
    }

    void print(){
        if(head != NULL){
            Node* curr = head;
            while(curr != NULL){
               cout<<curr->data<<" ";
                curr = curr->next; 
            }
            cout<<endl;
        }
    }

    void printInReverse(){
        if(head != NULL){
            Node* curr = head;
            while(curr->next != NULL){
                curr = curr->next;
            }
            while(curr != NULL){
                cout<<curr->data<<" ";
                curr = curr->prev;
            }
            cout<<endl;
        }
    }

    int getSize(){
        return size;
    }
};

int main(){
    LinkedList* list = new LinkedList();
    list->insertAtHead(7);
    list->insertAtHead(9);
    list->insertAtTail(8);
    list->insertAtHead(2);
    list->insertAtTail(1);

    list->print();
    list->printInReverse();
}