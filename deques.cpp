#include <iostream>

using namespace std;

class DeQue{
    private:
        int front;
        int rear;
        int size;
        int queCapacity;
        int* arr;

    bool isFull(){
        return this->size == this->queCapacity;
    }    

    public:
       DeQue(int capacity) : queCapacity(capacity), front(-1), rear(-1), size(0) {
           this->arr = new int[capacity];
       }

       int getSize(){
           return this->size;
       }

       bool isEmpty(){
           return this->size == 0;
       }

       int getFront(){
           if(isEmpty()) return -1;
           return arr[front];
       }

       int getRear(){
           if(isEmpty()) return -1;
           return arr[rear];
       }

       void enqueueFront(int data){
           if(isFull()){
               cout<<"Queue is Full. Can't enqueue"<<endl;
               return;
           }

           if(isEmpty()){
               front = rear = 0;
           }else{
               front = (front + queCapacity - 1) % queCapacity;
           }
           arr[front] = data;
           size++;
       }

       void enqueueRear(int data){
           if(isFull()){
               cout<<"Queue is Full. Can't enqueue"<<endl;
               return;
           }

           if(isEmpty()){
               front = rear = 0;
           }else{
               rear = (rear + 1) % queCapacity;
           }
           arr[rear] = data;
           size++;
       }

       int dequeueFront(){
           if(isEmpty()){
               cout<<"Queue is Empty. Can't dequeue"<<endl;
               return -1;
           }

           int data = arr[front]; 
           if(this->size == 1){
               front = rear = -1;
           }else{
               front = (front + 1) % queCapacity;
           }
           size--;
           return data;
       }

       int dequeueRear(){
           if(isEmpty()){
               cout<<"Queue is Empty. Can't dequeue"<<endl;
               return -1;
           }

           int data = arr[rear]; 
           if(this->size == 1){
               front = rear = -1;
           }else{
               rear = (rear + queCapacity - 1) % queCapacity;
           }
           size--;
           return data;
       }

       void printAll(){
           if(isEmpty()){
                return;
            }

            if(this->front <= this->rear){
                for(int i = this->front; i <= this->rear; i++){
                    cout<<this->arr[i]<<" ";
                }
            }else{
                for(int i = this->front; i <= this->queCapacity - 1; i++){
                    cout<<this->arr[i]<<" ";
                }
                for(int i = 0; i <= this->rear; i++){
                    cout<<this->arr[i]<<" ";
                }
            }
            cout<<endl;
       }     
};

int main(){
    DeQue queue(11);
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