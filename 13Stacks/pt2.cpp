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

char validPair(char p){
    if(p=='(') return ')';
    else if( p == '[') return ']';
    else if( p == '{') return '}';
}

bool validParenthesis(string s){
    stack<char> temp;
    if(s.empty()) return true;

    
    for(char ch : s){
        if(ch == '[' || ch == '{' || ch == '('){
            temp.push(ch);
        }else{
            if(temp.empty()) return false;
            else if(validPair(temp.top()) == ch){
                temp.pop();
            }else{
                return false;
            }
        }
    }

    return temp.empty();
}

int main(){
    string s = "((({{[[]]}})))(";
    cout<< validParenthesis(s);
}