#include <iostream>

using namespace std;

int increment(int &x){
    cout<<" Address of x in increment :: " << &x << endl;
    return ++x;
}

int incrementP(int* x){
    cout<<" Address of x in incrementP :: " << x << endl;
    return ++(*x);
}

int incrementV(int x){
    cout<<" Address of x in incrementV :: " << &x << endl;
    return ++x;
}

int main()
{
    int x = 5;
    cout<<" Address of x in main :: " << &x << endl;
    increment(x);
    cout<<" x value :: "<< x << endl;
    incrementP(&x);
    cout<<" x value :: "<< x << endl;
    incrementV(x);
    cout<<" x value :: "<< x << endl;
    return 0;
}
