#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void pushAtBottom(stack<int> &s, int val){ //space complexity of O(n)
    stack<int> temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    s.push(val);
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }

}

void recursivePushAtBottom(stack<int> & s, int val){ // space complexity of O(k)
    if(s.empty()){
        s.push(val);
        return;
    }
    int top = s.top();
    s.pop();
    recursivePushAtBottom(s, val);
    s.push(top);
}


void reverse(stack<int> &s){
    if(s.empty()) return;
    int top = s.top();
    s.pop();
    reverse(s);
    recursivePushAtBottom(s, top);
}


void stockSpan (vector<int> &prices){
    stack<int> s;
    vector<int> spans(prices.size());
    spans[0] = 1;
    s.push(0);
    for(int idx = 1; idx<prices.size(); idx++ ){
        int ans;
        while(!s.empty()&& prices[s.top()]<=prices[idx]){
            s.pop();
        }

        if(s.empty()){
            ans = idx + 1;
        }else {
            ans = idx-s.top();
        }

        spans[idx] = ans;
        s.push(idx);
    }

    for(int i = 0; i<spans.size(); i++){
        cout<<spans[i]<<" ";
    }
}


int main(){
    // stack<int>  s;
    // s.push(1);
    // s.push(2);
    // s.push(3);

    // pushAtBottom(s, 0);

    // reverse(s);

    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }


    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    stockSpan(stock);
}