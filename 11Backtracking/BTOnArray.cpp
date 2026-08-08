#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printArr(int arr[], int size){
    for(int i=0 ; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

void changeArr(int arr[], int n, int i=0){
    if(i==n){
        printArr(arr,n);
        return;
    }
    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i]-=2;
}

int main (){
    int arr[5]={0};
    changeArr(arr, 5);
    cout<<endl;
    printArr(arr, 5);
    return 0;
}