#include <iostream>

using namespace std;

void subSetHelper(int* arr, int size, int start, int* subset, int subsetSize){
    if(start == size) return;
    if(subsetSize == size) return;
    subSetHelper(arr, size, start + 1, subset, subsetSize);
    int* temp = new int[subsetSize + 1];
    cout<<"[ ";
    for(int i = 0; i < subsetSize; i++){
        temp[i] = subset[i];
        cout<<temp[i]<<" , ";
    }
    temp[subsetSize] = arr[start];
    cout<<temp[subsetSize]<<" ]"<<endl;
    subset = temp;
    subsetSize = subsetSize + 1;
    start = start + 1;
    subSetHelper(arr, size, start, subset, subsetSize);
}

void printAllSubsets(int* arr, int size){
    cout<<"[ ]"<<endl;
    subSetHelper(arr, size, 0, new int[0], 0);
}

int main()
{
    int size;
    cin>>size;
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    printAllSubsets(arr, size);
    return 0;
}
