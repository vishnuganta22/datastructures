// Rule - All Strings in C has be NULL terminated
// '\0' is the NULL character

# include <iostream>
# include <cstring>

using namespace std;

int main(){
    // when we pass char pointer to cin it tries to derefrence and print the data 
    // but when we pass int pointer to cin it prints the address
    
    // cin only reads strings till space or newline if you want read strings with spaces check for an alternative.
    // without specifing the size of the char array we can't read string using cin methods. so we need to initialise. 
    // intialising like this char* c = "test message"; in CPP is throwing a warning.

    string name, phoneNumber, address;
    char nickName[20];
    char* surname = new char[20];
    cout<<"Enter your name :: ";
    cin>>name;
    cout<<"Enter your nick name ::";
    cin>>nickName;
    cout<<"Enter your surname :: ";
    cin>>surname;
    cout<<"Enter your phoneNumber :: ";
    cin>>phoneNumber;
    cout<<"Enter your address :: ";
    cin>>address;
    int arr[5] = {1, 2, 3, 4, 5};
    char v = 'v';
    char* p = &v;
    cout<<p<<endl;
    cout<< sizeof(name) <<endl;
    cout<<"Name is :: " << name<<endl;
    cout<<"NickName is :: "<<nickName<<endl;
    cout<<"surname is :: "<<nickName<<endl;
    cout<<"Arr is :: " << arr << endl;
    cout<<"Phone Number is :: " << phoneNumber << endl;
    cout<<"Address Number is :: " << address << endl;
    cout<<"Address of arr is  :: " << &arr << endl;
    cout<<"Length of Name is  :: " << name.size() << endl;
    cout<<"Length of phoneNumber is :: " << phoneNumber.length() << endl;
    cout<<"Length of address is :: " << strlen(address.c_str()) << endl;
    cout<<"Length of nickName is :: " << strlen(nickName) << endl;
    cout<<"Length of surname is :: " << strlen(surname) << endl;
    return 0;
}