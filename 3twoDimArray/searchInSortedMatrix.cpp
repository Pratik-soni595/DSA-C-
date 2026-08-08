#include<iostream>
using namespace std;

void staircaseSearch (int arr[][4], int n, int m, int key){
    int row = 0;
    int col = m-1;
    while(row<n && col>=0){
        int start = arr[row][col];
        if(start == key) {
            cout<<row<<", "<<col;
            return;
        }else if(start<key){
            row++;
        }else{
            col--;
        }
    }
}

int main (){
    int arr[3][4] = {
        {  1,  2,  3,  4 },
        {  5,  6,  7,  8 },
        {  9, 10, 11, 12 }
    };
    staircaseSearch(arr, 3, 4, 10);
}