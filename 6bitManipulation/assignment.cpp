#include <iostream>
using namespace std;

int clearRangeOfBits2(int n, int i, int j){
    int m1 = (~0)<<(j+1);
    int m2 = ~((~0)<<i);
    int mask = m1|m2;
    int ans = n&mask;
    return ans;    
}
int main (){
    int n = 15;
    cout<<clearRangeOfBits2(31, 1,3);
}