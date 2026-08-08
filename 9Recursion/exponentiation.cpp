#include <iostream>
using namespace std;

int exponentiation(int x, int n){
    if(n==0) return 1;
    return x*exponentiation(x,n-1);
}

int exp(int x, int n){
    if(n==0){
        return 1;
    }
    int halfPower = exp(x,n/2);
    int hpSquare = halfPower*halfPower;
    if(n%2 != 0) return hpSquare*x;
    return hpSquare;
}

int main(){
    cout<<exponentiation(2,3)<<endl;
    cout<<exp(2,5);
}