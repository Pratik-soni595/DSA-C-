#include<iostream>
#include<string>

using namespace std;

void subsets(string str, string sub = ""){
    if(str.size() == 0){
        cout<<sub<<endl;
        return;
    }

    char ch = str[0];
    subsets(str.substr(1,str.size()-1), sub+ch); // yes choice
    subsets(str.substr(1,str.size()-1), sub); // no choice
}

int main(){
    string str = "abc";
    subsets(str);
    return 0;
}