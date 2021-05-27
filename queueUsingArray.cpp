#include <iostream>

using namespace std;

class QueueWithArray{
    private:
        int size;
        int capacity;
        int* queue;
        int front;
        int rear;

        bool isFull(){
            return size >= capacity;
        }

    public:
        QueueWithArray(int capacity){
            this->capacity = capacity;
            this->queue = new int[capacity];
            this->front = this->rear = -1;
            this->size = 0;
        }

        void enqueue(int data){
            if(isFull()){
                cout<<"Queue is Full"<<endl;
                return;
            }

            if(isEmpty()){
                front = rear = 0;
            }else{
                if(rear >= capacity-1){
                    rear = 0;
                }else{
                    rear++;
                }
            }
            queue[rear] = data;
            size++;
        }

        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }

            int result = queue[front];
            if(front >= capacity-1){
                front = 0;
            }else{
                front++;
            }
            size--;
            return result;
        }

        int peek(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return queue[front];
        }

        bool isEmpty(){
            return size <= 0;
        }

        void printAll(){
            if(isEmpty()){
                return;
            }

            if(this->front <= this->rear){
                for(int i = this->front; i <= this->rear; i++){
                    cout<<this->queue[i]<<" ";
                }
            }else{
                for(int i = this->front; i <= this->capacity - 1; i++){
                    cout<<this->queue[i]<<" ";
                }
                for(int i = 0; i <= this->rear; i++){
                    cout<<this->queue[i]<<" ";
                }
            }
            cout<<endl;
        }    
};

int main(){
    QueueWithArray* queue = new QueueWithArray(5);
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->enqueue(6);
    cout<<queue->dequeue()<<endl;
    queue->enqueue(6);
    cout<<queue->dequeue()<<endl;
    queue->enqueue(7);
    cout<<queue->peek()<<endl;
    queue->printAll();
}