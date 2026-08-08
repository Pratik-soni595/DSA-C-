#include<iostream>
using namespace std;


int updateBit(int n, int i, bool bit){
    int mask = 1<<i;
    int ans;
    if(bit == 0){
        ans = n&(~mask);
    }else{
        ans = n|mask;
    }
    return ans;
}

int clearBits(int n, int i){
    int mask = (~0)<<i;
    return n&mask;
}

int countSetBits(int n){
    int count = 0;
    int mask = 1;
    while(n!=0){
        count+= n&mask;
        n= n>>1;
    }
    return count;
}

int fastExponentiation(int n, int x){
    int ans = 1;
    int mul = n;
    while(x>0){
        if(x&1) ans*=n;
        n*=n;
        x = x>>1;
    }
    return ans;
}   

int main (){
    int n = 5;
    int ans = updateBit(7, 2, 0);
    cout<<ans<<endl;

    cout<<clearBits(15,3)<<endl;

    cout<<countSetBits(15)<<endl;

    cout<<fastExponentiation(3,4)<<endl;

    return 0;
}   