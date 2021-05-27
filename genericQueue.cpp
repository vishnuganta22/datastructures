#include <iostream>

using namespace std;

template<typename T>
class QueueWithArray{
    private:
        T* queue;
        int front;
        int rear;
        int capacity;

    public:
        QueueWithArray(int capacity){
            this->queue = new T[capacity];
            this->front = this->rear = -1;
            this->capacity = capacity;
        }

        bool isEmpty(){
            return this->front == -1 && this->rear == -1;
        }

        bool isFull(){
            return (this->front == ((this->rear % this->capacity) + 1));
        }

        void enqueue(T data){
            if(isFull()){
                throw "Queue is Full";
            }

            if(isEmpty()){
                this->front = this->rear = 0;
            }else{
                this->rear = (this->rear % this->capacity) + 1;
            }
            this->queue[this->rear] = data;
        }

        T dequeue(){
            if(isEmpty()){
                throw "Queue is Empty";
            }

            int result = this->queue[this->front];
            if(this->front == this->rear){
                this->front = this->rear = -1;
            }else{
                this->front = (this->front % this->capacity) + 1;
            }
            return result;
        }

        T peek(){
            if(isEmpty()){
                throw "Queue is Empty";
            }

            return queue[front];
        }

        void printAll(){
            if(isEmpty()){
                return;
            }

            int i = this->front;
            do{
                cout<<this->queue[i]<<" ";
                i = (i % this->capacity) + 1;
            }while(i != this->rear);
            cout<<endl;
        }    
};

int main(){
    QueueWithArray<int>* queue = new QueueWithArray<int>(5);
    try
    {
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
    catch(const char* e)
    {
        cout<<"Exception :: " << e << endl;
    }
}