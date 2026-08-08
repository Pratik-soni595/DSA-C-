#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string org,string ans, int i , int track[26]){
    if(i==org.size()){
        return ans;
    }
    if(track[int(org[i])-'a']==0){
        ans.push_back(org[i]);
        track[int(org[i])-'a'] =1;
    }
    return removeDuplicates(org, ans, i+1, track);


}



int main(){
    string name = "pratikkksoooonnii";
    // string ans = removeDuplicates(name);
    string ans = "";
    int track[26]={0};
    cout<<removeDuplicates(name, ans, 0,track);
    return 0;
}