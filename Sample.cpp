#include <iostream>

using namespace std;

class Vishnu
{
private:
    int x;

public:
    Vishnu(int value)
    {
        x = value;
    }
    void display()
    {
        cout << x << endl;
    }
};

int main()
{
    cout << "Hello World" << endl;
    Vishnu *vishnu = new Vishnu(9); // new operator using the constructor
    vishnu->display();

    Vishnu vishnuganta(11); // default constructor
    vishnuganta.display();
}