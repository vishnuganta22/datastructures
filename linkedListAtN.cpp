#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    void insert(int digit, int position)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid position to insert data" << endl;
            return;
        }
        else
        {
            Node *temp1 = new Node();
            temp1->data = digit;
            temp1->link = NULL;
            if (position == 0)
            {
                temp1->link = head;
                head = temp1;
                size++;
                return;
            }

            Node *temp2 = head;
            for (int i = 0; i < position - 1; i++)
            {
                temp2 = temp2->link;
            }
            temp1->link = temp2->link;
            temp2->link = temp1;

            size++;
        }
    }

    void remove(int position)
    {
        if (position < 0 || position > size - 1)
        {
            cout << "Invalid position to delete data" << endl;
            return;
        }
        else
        {
            if (position == 0)
            {
                Node *temp = head;
                head = head->link;
                delete temp;
                size--;
            }
            else
            {
                Node *temp = head;
                for (int i = 0; i < position - 1; i++)
                {
                    temp = temp->link;
                }
                Node *temp1 = temp->link;
                temp->link = temp1->link;
                delete temp1;
                size--;
            }
        }
    }

    int getSize()
    {
        return this->size;
    }

    void printAll()
    {
        Node *temp = head;
        while (temp->link != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << temp->data << endl;
    }

    void reverseByIteration()
    {
        Node *currentNode = head;
        Node *previousNode = NULL;
        while (currentNode != NULL)
        {
            Node *next = currentNode->link;
            currentNode->link = previousNode;
            previousNode = currentNode;
            currentNode = next;
        }
        head = previousNode;
    }

    void reverseByRecurssion(Node* currentNode, Node* previousNode){
        if(currentNode==NULL){
            head = previousNode;
            return;
        }

        Node* nextNode = currentNode->link;
        currentNode->link = previousNode;
        reverseByRecurssion(nextNode, currentNode);
    }

    void printByRecurssion(Node *currentNode)
    {
        if (currentNode == NULL)
        {
            cout << endl;
            return;
        }
        cout << currentNode->data << " ";
        printByRecurssion(currentNode->link);
    }

    void printReverseByRecurssion(Node *currentNode){
        if (currentNode == NULL)
        {
            return;
        }
        printReverseByRecurssion(currentNode->link);
        cout << currentNode->data << " ";
    }

    Node *getHead()
    {
        return head;
    }
};

int main()
{
    int size;
    cout << "How many numbers ? " << endl;
    cin >> size;

    int digit, position;
    LinkedList *list = new LinkedList();
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter the number " << endl;
    //     cin >> digit;
    //     cout << "Enter position " << endl;
    //     cin >> position;
    //     list->insert(digit, position);
    //     cout << "Printing all items in the Linked List ::";
    //     list->printAll();
    // }

    list->insert(2, 0);
    list->insert(4, 1);
    list->insert(3, 2);
    list->insert(5, 3);
    list->insert(9, 4);
    list->printAll();
    list->reverseByIteration();
    list->printByRecurssion(list->getHead());
    list->printReverseByRecurssion(list->getHead());
    cout<<endl;
    list->reverseByRecurssion(list->getHead(), NULL);
    list->printByRecurssion(list->getHead());
}