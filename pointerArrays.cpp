#include <iostream>

using namespace std;


int main()
{
    int* arr = new int[5];
    for(int i=0;i<5;i++){
        arr[i] = i * 2;
    }
    int* p = arr;
    int x = 5;
    arr = &x;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<arr + i<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<p + i<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<p[i]<<endl;
    }
    return 0;
}