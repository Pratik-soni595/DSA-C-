#include<iostream>
using namespace std;

int gridWays(int n, int m){
    if(n==1&&m==1){
        return 1;
    }else if(n==0||m==0){
        return 0;
    }

    return gridWays(n-1,m) +gridWays(n, m-1);
}

int main (){
    cout<<gridWays(3,3);
}