#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *head;

void insert(int digit)
{
    if (head == NULL)
    {
        head = new Node;
        head->data = digit;
        head->link = NULL;
    }
    else
    {
        Node *temp1 = new Node;
        temp1->data = digit;
        temp1->link = NULL;

        Node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = temp1;
    }
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

int main()
{
    head = NULL;

    int size;
    cout << "How many numbers ? " << endl;
    cin >> size;

    int digit;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number " << endl;
        cin >> digit;
        insert(digit);
    }

    cout << "Printing all items in the Linked List ::";
    printAll();
}