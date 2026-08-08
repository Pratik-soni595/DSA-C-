#include<iostream>
using namespace std;

void binaryStrings(int n, string ans = "", int lastPlace =0){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(lastPlace==0){
        binaryStrings(n-1,ans+'0', 0 );
        binaryStrings(n-1,ans+'1', 1);
    }else{
        binaryStrings(n-1, ans+'0', 0);
    }
}

int main(){
    binaryStrings(2);
}