#include <iostream>
using namespace std;

int getIthBit(int n, int i){
    int mask = 1<<i;
    if(!(n&mask)){
        return 0;
    }else{
        return 1;
    }
}

void setIthBit(int &n, int i){
    int mask = 1<<i;
    n= n|mask;
}
void clearIthBit(int &n, int i){
    int mask = ~(1<<i);

    n= n&mask;
}

bool isPowOf2(int n){
    int mask = n-1;
    if(!(n&(mask))) return true;
    else return false;
}

int main(){
    cout<<getIthBit(5, 1)<<endl; 
    int n =5;
    setIthBit(n, 1); 
    cout<<n<<endl;
    clearIthBit(n,1);
    cout<<n<<endl;

    cout<<isPowOf2(8)<<endl;
    return 0;

}