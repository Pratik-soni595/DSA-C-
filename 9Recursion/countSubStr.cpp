#include<iostream>
#include<string>
using namespace std;

int countSubStr(string str, int i, int j, int size){
    if(size==1){
        return 1;
    }
    if(size<=0){
        return 0;
    }

    int res = countSubStr(str, i+1, j, size-1) + countSubStr(str, i, j-1, size-1) - countSubStr(str, i+1, j-1, size-2); //important line
    if(str[i]==str[j]) res++;

    return res;
}

int main(){
    string str  = "abcab";
    cout<<countSubStr(str,0,4,str.size());
    
    return 0;
}