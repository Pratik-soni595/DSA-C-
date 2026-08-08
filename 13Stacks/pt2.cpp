#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> arr){
    vector<int> ans(arr.size());
    stack<int> track;
    for(int i = arr.size()-1; i>= 0; i--){
        while(!track.empty() && track.top()<=arr[i]){
            track.pop();
        }
        
        if(track.empty()){
            ans[i] = -1;
        }else{
            ans[i] = track.top();
        }
        track.push(arr[i]);
    }
    return ans;
}

bool validParenthesis(string s){
    stack<char> temp;
    if(s.empty()) return;

    temp.push(s[0]);

    for(int i = 1; i<s.size(); i++){
        if(temp.top() == s[i]){
            temp.pop();
        }else{
            temp.push(s[i]);
        }
    }
}

int main(){
    
}