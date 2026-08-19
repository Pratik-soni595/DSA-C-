#include <iostream>
#include <stack>

using namespace std;

int maxAreainHist(int height[], int n){
    int nsl[n] = {-1};
    int nsr[n] = {n};

    stack<int> s;
    s.push(height[0]);

    for(int i = 0; i<n; i++){
        while(!s.empty()&&height[s.top()]<height[i]){
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] == s.top();
        }
        s.push(i);
    }

    while(!s.empty()){s.pop();}
    
    for(int i = n; i>=0; i--){
        while(!s.empty()&&height[s.top()<height[i]]){
            s.pop();
        }
        if(s.empty()){
            nsr[i] = -1;
        }else{
            nsr[i] = s.top();
        }
        s.push(i);
    }
}