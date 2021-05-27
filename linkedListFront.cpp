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

public:
    LinkedList()
    {
        this->head = NULL;
    }

    void insert(int digit)
    {
        Node *temp = new Node;
        temp->data = digit;
        if (head != NULL)
            temp->link = head;
        head = temp;
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
};

int main()
{
    int size;
    cout << "How many numbers ? " << endl;
    cin >> size;

    int digit;
    LinkedList *list = new LinkedList();
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number " << endl;
        cin >> digit;
        list->insert(digit);
        cout << "Printing all items in the Linked List ::";
        list->printAll();
    }
}