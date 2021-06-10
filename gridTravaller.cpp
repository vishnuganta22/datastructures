#include <iostream>

using namespace std;

long path(int m, int n, long** arr){
    if(m == 0 || n == 0) return 0;
    if(m == 1 || m == 1) return 1;
    if(arr[m][n] != 0) return arr[m][n];
    long x = path(m-1, n, arr);
    arr[m-1][n] = arr[n][m-1] = x;
    long y = path(m, n-1, arr);
    arr[m][n-1] = arr[n-1][m] = y;
    return x + y;
}

long pathCount(int m, int n){
    long** arr = new long*[m+1];
    for(int i=0;i<m+1;i++){
        arr[i] = new long[n+1];
    }
    return path(m, n, arr);
}

long pathCountLong(int m, int n){
    if(m == 0 || n == 0) return 0;
    if(m == 1 || m == 1) return 1;
    return pathCountLong(m-1, n) + pathCountLong(m, n-1);
}

int main()
{
    int m,n;
    cout<<"Enter Grid Length :: ";
    cin>>m;
    cout<<endl<<"Enter Grid height :: ";
    cin>>n;
    cout<<endl<<"Result :: " <<pathCountLong(m, n);
    return 0;
}
