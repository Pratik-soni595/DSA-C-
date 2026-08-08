#include <iostream>
#include <string>
using namespace std;

bool areSameAfterSwap (string word1, string word2){
    if(word1.length()!=word2.length()) return false;
    for(int i=0; i<word1.length(); i++){
        for(int j = i; j<word1.length(); j++){
            string temp = word2;
            swap(temp[i], temp[j]);
            if(word1 == temp) return true;
        }
    }
    return false;
}

int main(){
    string s1 = "pratik";
    string s2 = "partik";
    cout<<areSameAfterSwap(s1, s2);
}