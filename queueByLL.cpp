#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class QueueLL{
    private:
        Node<T>* front;
        Node<T>* back;
        int size;
    public:
        QueueLL(){
            this->size = 0;
            this->front = NULL;
            this->back = NULL;
        }

        bool isEmpty(){
            return this->front == NULL;
        }

        void enqueue(T data){
            if(isEmpty()){
                Node<T>* node = new Node<T>();
                node->data = data;

                this->front = node;
                this->back = node;
            }else{
                Node<T>* node = new Node<T>();
                node->data = data;
                this->back->next = node;

                this->back = node;
            }
            size++;
        }

        T dequeue(){
            if(isEmpty()){
                throw "Queue is Empty";
            }
            
            T result = this->front->data;
            Node<T>* node = this->front;
            this->front = this->front->next;
            delete node;
            size--;
            return result;
        }

        T peek(){
            if(isEmpty()){
                throw "Queue is Empty";
            }else{
                return this->front->data;
            }
        }

        int getSize(){
            return this->size;
        }

        void printAll(){
            if(isEmpty()){
                throw "Queue is Empty";
            }

            Node<T>* node = this->front;
            do{
                cout<<node->data<<" ";
                node = node->next;
            }while(node != NULL);
            cout<<endl;
        }   
};

int main(){
    QueueLL<int>* queue = new QueueLL<int>();
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
        cout<<queue->dequeue()<<endl;
        cout<<queue->dequeue()<<endl;
        cout<<queue->dequeue()<<endl;
        cout<<queue->dequeue()<<endl;
        cout<<queue->dequeue()<<endl;
        cout<<queue->dequeue()<<endl;
        cout<<queue->dequeue()<<endl;
    }
    catch(const char* e)
    {
        cout<<"Exception :: " << e << endl;
        queue->enqueue(1);
        queue->printAll();
    }
}