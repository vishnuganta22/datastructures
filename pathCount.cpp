#include <iostream>

using namespace std;

int pathCount(int n, int m){
    if(n == 1 || m == 1) return 1;
    else{
        return pathCount(n, m-1) + pathCount(n-1, m);
    }
}

int main(){
    int n,m;
    cout<<"Enter N and M values"<<endl;
    cin>>n>>m;
    cout<<pathCount(n, m)<<endl;
}