#include <iostream>
using namespace std; 

void spiralMatrix(int arr[][5], int n, int m){
    int stRow = 0, endRow = n-1, stCol = 0, endCol = m-1;
    while(stRow<=endCol && stCol<=endRow){
        for(int i =stCol; i<=endCol; i++ ){
            cout<<arr[stRow][i]<<" ";
        }
        for(int i =stRow+1; i<=endRow; i++ ){
            cout<<arr[i][endCol]<<" ";
        }
        for(int i =endCol-1; i>=stCol; i-- ){
            cout<<arr[endRow][i]<<" ";
        }
        for(int i =endRow-1; i>stRow; i-- ){
            cout<<arr[i][stCol]<<" ";
        }
        stRow++;
        stCol++;
        endRow--;
        endCol--;
    }
}

int main (){
    int arr[5][5] = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int arr2[4][5] = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };
    
    int n = 4, m=5;
    spiralMatrix(arr2, n, m);
}