#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DeQue{
    private:
        int size;
        Node* front;
        Node* rear;

        Node* createNode(int data){
            Node* node = new Node();
            node->data = data;
            node->next = node->prev = NULL;
            return node;
        }

    public:
        DeQue(){
            this->front = this->rear = NULL;
            this->size = 0;
        }

        bool isEmpty(){
            return this->size == 0;
        }

        int getSize(){
            return this->size;
        }

        int getFront(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            return this->front->data;
        }

        int getRear(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            return this->rear->data;
        }

        void enqueueFront(int data){
            Node* temp = createNode(data);
            if(!isEmpty()){
                front->prev = temp;
                temp->next = this->front;
            }else{
                this->rear = temp;
            }
            this->front = temp;
            size++;
        }

        void enqueueRear(int data){
            Node* temp = createNode(data);
            
            if(!isEmpty()){
                temp->prev = this->rear;
                this->rear->next = temp;
            }else{
                this->front = temp;
            }
            this->rear = temp;
            size++;
        }

        int dequeueFront(){
            if(isEmpty()){
                cout<<"Queue is Empty can't dequeue"<<endl;
            }
            int data = this->front->data;

            Node* temp = this->front->next;
            delete front;
            if(size == 1){
                this->front = this->rear = NULL;
            }else{
                this->front = temp;
                this->front->prev = NULL;
            }
            size--;
            return data;
        }

        int dequeueRear(){
            if(isEmpty()){
                cout<<"Queue is Empty can't dequeue"<<endl;
            }
            int data = this->rear->data;

            Node* temp = this->rear->prev;
            delete rear;
            if(size == 1){
                this->front = this->rear = NULL;
            }else{
                this->rear = temp;
                this->rear->next = NULL;
            }
            size--;
            
            return data;
        }

        void printAll(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return;
            }

            Node* node = this->front;
            do{
                cout<<node->data<<" ";
                node = node->next;
            }while(node != NULL);
            cout<<endl;
        }
            
};

int main(){
    DeQue queue;
    queue.enqueueFront(1);
    queue.enqueueRear(2);
    queue.enqueueFront(3);
    queue.enqueueRear(4);
    queue.enqueueFront(5);
    queue.enqueueRear(6);
    queue.enqueueFront(7);
    queue.enqueueRear(8);
    queue.enqueueFront(9);
    queue.enqueueRear(10);
    queue.enqueueFront(11);
    queue.enqueueRear(12);
    queue.enqueueFront(13);
    queue.printAll();
    cout<<queue.dequeueFront()<<endl;
    cout<<queue.dequeueRear()<<endl;
    queue.printAll();
    queue.enqueueFront(12);
    queue.enqueueFront(13);
    queue.printAll();
}