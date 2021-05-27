#include <iostream>
#include <vector>

using namespace std;

void printAllInVector(vector<int> b){

    cout << "| ";
    for(int i=0; i < b.size(); i++){
        cout << b[i] << " | "; 
    }
    cout << endl;
}

int main(){
    vector<int> v(3);

    v[0] = 1;
    v[1] = 7;
    v[2] = 9;

    v.push_back(11);

    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v.at(2) <<endl;

    printAllInVector(v);

    return 0;
}