#include <iostream>

using namespace std;

// At the runtime compiler interpets the array arguments as pointers 
// so the int sumOfElements(int A[], int size) is interpreted as int sumOfElements(int* A, int size)
// where the int* A corresponds to the address of the first element of the array that is passed to this function.
// so we can directly send the pointer instead of the int A[].
// Arrays are always passed as reference parameters.
// For Arrays their is no callByValues. It is always callByReference.
int sumOfElements(int A[], int size){
    cout<<" Length of A in sumOfElements :: " << sizeof(A) << endl;
    int sum = 0;
    for(int i =0;i<size;i++){
        sum += A[i];
    }
    return sum;
}

int sumOfElementsP(int* A, int size){
    int sum = 0;
    for(int i =0;i<size;i++){
        sum += A[i];
    }
    return sum;
}


int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int* arr = new int[5];
    for(int i=0;i<5;i++){
        arr[i] = i * 2;
    }
    int* p = arr;
    int x = 5;
    // Returns the size of pointer (Either 4 or 8 base on your computer architure) Since 'p' points to a pointer
    cout<<" Length of array :: " << sizeof(p) << endl;
    cout<<" Length of int :: " << sizeof(x) << endl;
    // Returns the size of Array A
    cout<<" Length of A in Main :: " << sizeof(A) << endl;
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
    cout<<"Sum of elements in Array :: "<<sumOfElements(A, 5) << endl;
    cout<<"Sum of elements in Array :: "<<sumOfElementsP(A, 5) << endl;
    return 0;
}