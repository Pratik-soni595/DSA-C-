#include<iostream>
using namespace std;

int tilingProblem(int n){
    if(n==1||n==0){
        return 1;
    }
    return tilingProblem(n-1)+tilingProblem(n-2);
}


int main(){
    cout<<tilingProblem(5);
    return 0;
}