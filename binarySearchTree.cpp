#include <iostream>
#include <vector>

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

class BinarySearchTree{ 
    private:
        Node* treeRoot;

        Node* getNewNode(int x){
            Node* node = new Node();
            node->data = x;
            node->leftNode = node->rightNode = NULL;
            return node;
        }

        Node* insert(Node* root, int x){
            if(root == NULL){
                root = getNewNode(x);
            }else if(x <= root->data ){
                root->leftNode = insert(root->leftNode, x);
            }else{
                root->rightNode = insert(root->rightNode, x);
            }
            return root;
        }

        bool search(Node* root, int x){
            if(root == NULL){
                return false;
            }else if(root->data == x){
                return true;
            }else if(x < root->data ){
                return search(root->leftNode, x);
            }else {
                return search(root->rightNode, x);
            }
        }

        Node* get(Node* root, int x){
            if(root == NULL){
                return NULL;
            }else if(root->data == x){
                return root;
            }else if(x < root->data){
                return get(root->leftNode, x);
            }else{
                return get(root->rightNode, x);
            }
        }

        void setRoot(Node* root){
            this->treeRoot = root;
        }

        Node* minNode(Node* root){
            if(root == NULL){
                cout<<"Error :: Tree is Empty"<<endl;
                return NULL;
            }else if(root->leftNode == NULL){
                return root;
            }else{
                return minNode(root->leftNode);
            }
        }

        int min(Node* root){
            if(root == NULL){
                cout<<"Error :: Tree is Empty"<<endl;
                return -1;
            }else if(root->leftNode == NULL){
                return root->data;
            }else{
                return min(root->leftNode);
            }
        }

        Node* maxNode(Node* root){
            if(root == NULL){
                cout<<"Error :: Tree is Empty"<<endl;
                return NULL;
            }else if(root->rightNode == NULL){
                return root;
            }else{
                return maxNode(root->rightNode);
            }
        }

        int max(Node* root){
            if(root == NULL){
                cout<<"Error :: Tree is Empty"<<endl;
                return -1;
            }else if(root->rightNode == NULL){
                return root->data;
            }else{
                return max(root->rightNode);
            }
        }

        int height(Node* root){
            if(root == NULL){
                return -1;
            }else{
                return std::max(height(root->leftNode), height(root->rightNode)) + 1;
            }
        }

        // Traversal in Binary Search Tree can done in 2 Ways
        // 1.Breadth First Traversal (Nodes at the same level will be addressed first).Breadth First Traversal is called as Level-Order traversal
        // 2.Depth First Traversal.
        // Depth First Traversal can be classified into 3 types.
        // a.PreOrder <Root><Left><Right>.
        // b.InOrder <Left><Root><Right>.
        // c.PostOrder <Left><Right><Root>.

        //TODO need to implement using the Queue
        void breadthFirstTraversel(QueueLL* queue){
            Node* node = this->getRoot();
            do{
                cout<<node->data<<" ";
                if(node->leftNode != NULL) {
                    queue->enqueue(node->leftNode);
                }

                if(node->rightNode != NULL){
                    queue->enqueue(node->rightNode);
                }

                node = queue->dequeue();    
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

        Node* deleteAElement(Node* root, int x){
            if(root == NULL) return NULL;
            if(x < root->data) root->leftNode = deleteAElement(root->leftNode, x);
            else if(x > root->data) root->rightNode = deleteAElement(root->rightNode, x);
            else{
                if(root->leftNode == NULL && root->rightNode == NULL){
                    delete root;
                    return NULL;
                }else if(root->leftNode == NULL){
                    Node* right = root->rightNode;
                    delete root;
                    return right;
                }else if(root->rightNode == NULL){
                    Node* left = root->leftNode;
                    delete root;
                    return left;
                }else{
                    Node* min = minNode(root->rightNode);
                    root->data = min->data;
                    root->rightNode = deleteAElement(root->rightNode, min->data);
                }
            }
            return root;
        }

        void storeBSTNodesInVector(Node* root, vector<Node *> &vector){
            if(root == NULL){
                return;
            }

            storeBSTNodesInVector(root->leftNode, vector);
            vector.push_back(root);
            storeBSTNodesInVector(root->rightNode, vector);
        }

        Node* buildBST(vector<Node*> &vector, int start, int end){
            if(start > end){
                return NULL;
            }

            int mid = (start + end) / 2;
            Node* root = vector.at(mid);

            root->leftNode = buildBST(vector, start, mid-1);
            root->rightNode = buildBST(vector, mid+1, end);

            return root;
        }

        Node* getSuccessor(Node* root, int data){
            Node* node =  get(data);

            if(node == NULL){
                return NULL;
            }

            if(node->rightNode != NULL){
                return minNode(node->rightNode);
            }else{
                Node* result = NULL;
                Node* temp = root;
                while(temp != node){
                    if(data < temp->data){
                        result = temp;
                        temp = temp->leftNode;
                    }else {
                        temp = temp->rightNode;
                    }
                }
                return result;
            }
        } 

    public:
        BinarySearchTree() {
            treeRoot = NULL;
        }

        Node* getRoot(){
            return this->treeRoot;
        }

        void insert(int x){
            setRoot(insert(this->getRoot(), x));
        }

        bool search(int x){
            return search(this->getRoot(), x);
        }

        int min(){
            return min(this->getRoot());
        }

        Node* minNode(){
            return minNode(this->getRoot());
        }

        int max(){
            return max(this->getRoot());
        }

        Node* maxNode(){
            return maxNode(this->getRoot());
        }

        int height(){
            return height(this->getRoot());
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

        void breadthFirstTraversel(){
            Node* root = this->getRoot();
            if(root == NULL){
                cout<<"Tree is empty";
                return;
            }

            QueueLL* queue = new QueueLL();
            cout<<"Start of breadthFirstTraversel"<<endl;
            breadthFirstTraversel(queue);
            cout<<"End of breadthFirstTraversel"<<endl;
            delete queue;
        }

        Node* get(int x){
            return get(this->getRoot(), x);
        }

        void deleteAElement(int x){
            setRoot(deleteAElement(this->getRoot(), x));
        }

        void convertToBalancedBT(){
            vector<Node *> nodes;
            storeBSTNodesInVector(this->getRoot(), nodes);
            this->setRoot(buildBST(nodes, 0, nodes.size()-1));
        }

        int getSuccessor(int data){
            Node* root = this->getRoot();
            if(root == NULL){
                cout<<"Tree is empty"<<endl;
                return -1;
            }
            Node* result = getSuccessor(root, data);
            if(result != NULL){
                return result->data;
            }else{
                return -1;
            }
        }
};

int main(){
    BinarySearchTree* tree = new BinarySearchTree();
    tree->insert(9);
    tree->insert(10);
    tree->insert(12);
    tree->insert(15);
    tree->insert(19);
    tree->insert(20);
    tree->insert(25);

    cout<<"Min of the Tree :: " <<tree->min()<<endl;
    cout<<"Max of the Tree :: " <<tree->max()<<endl;
    cout<<"Height of the Tree :: "<<tree->height()<<endl;
    tree->depthFirstTraversalPreOrder();
    tree->depthFirstTraversalInOrder();
    tree->depthFirstTraversalPostOrder();
    tree->deleteAElement(15);
    tree->breadthFirstTraversel();
    int number;
    cout<<"Enter a number to find"<<endl;
    cin>>number;
    if(tree->search(number)){
        cout<<"Found the number"<<endl;
    }else{
        cout<<"Number not found"<<endl;
    }
    tree->convertToBalancedBT();
    tree->breadthFirstTraversel();
    delete tree;
}