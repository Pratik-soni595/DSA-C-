#include<iostream>
#include<string>

using namespace std;
int main(){
    string str = "Wow Pratik";
    for(char ch : str){
        cout<<ch<<", ";
    }
    cout<<endl;
    cout<<str.length()<<endl;
    cout<<str.at(4)<<endl;
    cout<<str.substr(4,6)<<endl;  // to get a substring out of a string
    cout<<str.find("Pra", 3)<<endl; // it will give the first occrence of Wow in the string str, it starts checking from the given index
    return 0;
}