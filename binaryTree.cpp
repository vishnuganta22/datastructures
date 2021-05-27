#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* leftNode;
    Node* rightNode;
};

struct QNode{
    Node* data;
    QNode* next;
};

class QueueLL{
private:
        QNode* front;
        QNode* back;
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

        void enqueue(Node* data){
            if(isEmpty()){
                QNode* node = new QNode();
                node->data = data;

                this->front = node;
                this->back = node;
            }else{
                QNode* node = new QNode();
                node->data = data;
                this->back->next = node;

                this->back = node;
            }
            size++;
        }

        Node* dequeue(){
            if(isEmpty()){
                return NULL;
            }
            
            Node* result = this->front->data;
            QNode* node = this->front;
            this->front = this->front->next;
            delete node;
            size--;
            return result;
        }

        Node* peek(){
            if(isEmpty()){
                throw "Queue is Empty";
            }else{
                return this->front->data;
            }
        }

        Node* rear(){
            if(isEmpty()){
                throw "Queue is Empty";
            }else{
                return this->back->data;
            }
        }

        int getSize(){
            return this->size;
        }

        void printAll(){
            if(isEmpty()){
                throw "Queue is Empty";
            }

            QNode* node = this->front;
            do{
                cout<<node->data->data<<" ";
                node = node->next;
            }while(node != NULL);
            cout<<endl;
        }  
};

class BinaryTree{
    private:
        Node* treeRootNode;

        Node* getNewNode(int x){
            Node* node = new Node();
            node->data = x;
            node->leftNode = node->rightNode = NULL;
            return node;
        } 

        bool isSubTreeLesser(Node* node, int value){
            if(node == NULL){
                return true;
            }else if(node->data <= value && isSubTreeLesser(node->leftNode, value) && isSubTreeLesser(node->rightNode, value)){
                return true;
            }else{
                return false;
            }
        }

        bool isSubTreeGreater(Node* node, int value){
            if(node == NULL){
                return true;
            }else if(node->data > value && isSubTreeGreater(node->rightNode, value) && isSubTreeGreater(node->leftNode, value)){
                return true;
            }else{
                return false;
            }
        }

        bool isBinarySearchTree(Node* root){
            if(root == NULL){
                return true;
            }
            return isSubTreeLesser(root->leftNode, root->data) && isSubTreeGreater(root->rightNode, root->data) && isBinarySearchTree(root->leftNode) && isBinarySearchTree(root->rightNode); 
        }

        bool isBinarySearchTree(Node* root, int minValue, int maxValue){
            if(root == NULL){
                return true;
            }
            return root->data > minValue && root->data < maxValue && isBinarySearchTree(root->leftNode, minValue, root->data) && isBinarySearchTree(root->rightNode, root->data, maxValue);
        }

        void breadthFirstTraversel(QueueLL queue){
            Node* node = this->getRoot();
            do{
                cout<<node->data<<" ";
                if(node->leftNode != NULL) {
                    queue.enqueue(node->leftNode);
                }

                if(node->rightNode != NULL){
                    queue.enqueue(node->rightNode);
                }

                node = queue.dequeue();    
            }while(node != NULL);
            cout<<endl;
        } 

        void depthFirstTraversalPreOrder(Node* root){
            if(root == NULL){
                return;
            }
            cout<<root->data<<" ";
            depthFirstTraversalPreOrder(root->leftNode);
            depthFirstTraversalPreOrder(root->rightNode);
        } 

        void depthFirstTraversalInOrder(Node* root){
            if(root == NULL){
                return;
            }
            depthFirstTraversalInOrder(root->leftNode);
            cout<<root->data<<" ";
            depthFirstTraversalInOrder(root->rightNode);
        } 

        void depthFirstTraversalPostOrder(Node* root){
            if(root == NULL){
                return;
            }
            depthFirstTraversalPostOrder(root->leftNode);
            depthFirstTraversalPostOrder(root->rightNode);
            cout<<root->data<<" ";
        }  

        int height(Node* root){
            if(root == NULL){
                return -1;
            }else{
                return std::max(height(root->leftNode), height(root->rightNode)) + 1;
            }
        }

        Node* get(int x){
            Node* root = this->getRoot();
            if(root == NULL){
                return NULL;
            }
            QueueLL queue;
            queue.enqueue(root);
            Node* result = NULL;
            while(!queue.isEmpty()){
                Node* node = queue.dequeue();
                if(node->data == x){
                    result = node;
                    break;
                }

                if(node->leftNode != NULL) queue.enqueue(node->leftNode);
                if(node->rightNode != NULL) queue.enqueue(node->rightNode);
            }
            return result;
        }

        Node* getDeepestNode(){
            Node* root = this->getRoot();
            if(root == NULL){
                return NULL;
            }

            QueueLL queue;
            Node* previousNode = NULL;
            Node* node = this->getRoot();
            while(node != NULL){
                if(node->leftNode != NULL) queue.enqueue(node->leftNode);
                if(node->rightNode != NULL) queue.enqueue(node->rightNode);
                previousNode = node;
                node = queue.dequeue();
            }
            return previousNode;
        }

    public:
        BinaryTree(){
            this->treeRootNode = NULL;
        }

        Node* getRoot(){
            return this->treeRootNode;
        }

        bool isBinarySearchTree(){
            return isBinarySearchTree(this->getRoot(), INT8_MIN, INT8_MAX);
        }

        void insert(int x){
            if(this->treeRootNode == NULL){
                this->treeRootNode = getNewNode(x);
                return;
            }

            QueueLL queue;
            Node* node = treeRootNode;
            do{
                if(node->leftNode == NULL) break;
                else if(node->rightNode == NULL) break;
                else{
                    queue.enqueue(node->leftNode);
                    queue.enqueue(node->rightNode);
                }
                node = queue.dequeue(); 
            }while(!queue.isEmpty());
            if(node->leftNode == NULL) node->leftNode = getNewNode(x);
            else if(node->rightNode == NULL) node->rightNode = getNewNode(x);
        }

        void breadthFirstTraversel(){
            Node* root = this->getRoot();
            if(root == NULL){
                cout<<"Tree is empty"<<endl;
                return;
            }

            QueueLL queue;
            cout<<"Start of breadthFirstTraversel"<<endl;
            breadthFirstTraversel(queue);
            cout<<"End of breadthFirstTraversel"<<endl;
        }

        void depthFirstTraversalPreOrder(){
            cout<<"Start of depthFirstTraversalPreOrder"<<endl;
            depthFirstTraversalPreOrder(this->getRoot());
            cout<<endl;
            cout<<"End of depthFirstTraversalPreOrder"<<endl;
        }

        void depthFirstTraversalInOrder(){
            cout<<"Start of depthFirstTraversalInOrder"<<endl;
            depthFirstTraversalInOrder(this->getRoot());
            cout<<endl;
            cout<<"End of depthFirstTraversalInOrder"<<endl;
        }

        void depthFirstTraversalPostOrder(){
            cout<<"Start of depthFirstTraversalPostOrder"<<endl;
            depthFirstTraversalPostOrder(this->getRoot());
            cout<<endl;
            cout<<"End of depthFirstTraversalPostOrder"<<endl;
        }

        int height(){
            return height(this->getRoot());
        }

        void search(int x){
            Node* result = get(x);
            if(result != NULL){
                cout<<"Found"<<endl;
            }else{
                cout<<"Not Found"<<endl;
            }
        }

        void deleteAElement(int x){
            Node* root = this->getRoot();
            if(root == NULL){
                return;
            }

            if(root->leftNode == NULL && root->rightNode == NULL){
                delete this->treeRootNode;
                this->treeRootNode = NULL;
                return;
            }

            QueueLL queue;
            queue.enqueue(root);
            Node* result = NULL;
            Node* deepest = NULL;
            Node* deepestPL = NULL;
            Node* deepestPR = NULL;
            Node* node = NULL;
            while(!queue.isEmpty()){
                deepest = queue.peek();
                node = queue.dequeue();
                if(node->data == x){
                    result = node;
                }

                if(node->leftNode != NULL){
                    queue.enqueue(node->leftNode);
                    deepestPL = node;
                    deepestPR = NULL;
                }

                if(node->rightNode != NULL){
                    queue.enqueue(node->rightNode);
                    deepestPR = node;
                    deepestPL = NULL;
                }
            }

            if(result != NULL){
                result->data = deepest->data;
                delete deepest;
                if(deepestPL != NULL){
                    deepestPL->leftNode = NULL;
                }
                if(deepestPR != NULL){
                    deepestPR->rightNode = NULL;
                }
            }
        }

        //TODO
        void convertToBST(){
            
        }     
};

int main(){
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    cout<<"isBinarySearchTree :: " << tree.isBinarySearchTree() << endl;
    tree.depthFirstTraversalPreOrder();
    tree.depthFirstTraversalInOrder();
    tree.depthFirstTraversalPostOrder();
    tree.search(9);
    tree.search(1);
    tree.search(25);
    tree.deleteAElement(1);
    tree.breadthFirstTraversel();
}