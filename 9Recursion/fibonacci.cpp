#include <iostream>
using namespace std;

int fibonacciNum(int n){
    if(n==1){
        return 1;
    }else if(n==0){
        return 0;
    }

    return fibonacciNum(n-1) + fibonacciNum(n-2);
}

int main(){
    cout<<fibonacciNum(5);
    return 0;
}