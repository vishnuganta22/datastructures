#include <iostream>

using namespace std;

int fibOld(int n){
    if(n <= 2) return 1;
    return fibOld(n-1) + fibOld(n-2);
}

int fib(int n, int* arr){
    if(arr[n] > 0) return arr[n];
    int n1 = fib(n-1, arr);
    arr[n-1] = n1;
    int n2 = fib(n-2, arr);
    arr[n-2] = n2;
    return n1 + n2;
}

int fibIter(int n){
    if(n <= 2) return 1;
    int* arr = new int[n+1]{0, 1, 1};
    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

//1134903170
int main(){
    int n;
    cout<<"Enter n value :: ";
    cin>>n;
    int* arr = new int[n+1]{0, 1, 1};
    // current date/time based on current system
    time_t now = time(0);
    // convert now to string form
    char* dt = ctime(&now);
    cout << "The local date and time is Before :: " << dt << endl;
    cout<<"fib("<<n<<") :: "<<fib(n, arr)<<endl;
    now = time(0);
    // convert now to string form
    dt = ctime(&now);
    cout << "The local date and time is After :: " << dt << endl;
    
    now = time(0);
    // convert now to string form
    dt = ctime(&now);
    cout << "The local date and time is Before :: " << dt << endl;
    cout<<"fibOld("<<n<<") :: "<<fibOld(n)<<endl;
    now = time(0);
    // convert now to string form
    dt = ctime(&now);
    cout << "The local date and time is After :: " << dt << endl;
    
    now = time(0);
    // convert now to string form
    dt = ctime(&now);
    cout << "The local date and time is Before :: " << dt << endl;
    cout<<"fibIter("<<n<<") :: "<<fibIter(n)<<endl;
    now = time(0);
    // convert now to string form
    dt = ctime(&now);
    cout << "The local date and time is After :: " << dt << endl;
    
    
    return 0;
}