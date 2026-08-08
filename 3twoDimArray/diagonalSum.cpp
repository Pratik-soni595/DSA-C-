#include<iostream>
using namespace std;

int diagonalSum(int arr[][5], int n){
    int sum = 0;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(i==j || i+j ==n-1){
                // if(i==j && i+j ==n-1) continue;
                sum+=arr[i][j];
            }
        }
    }
    return sum;
}

int main(){
    int arr[5][5] = {
        {  1,  2,  3,  4,  5 },
        {  6,  7,  8,  9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 }
    };
    
    cout<<diagonalSum(arr, 5);
    return 0;
}