#include<iostream>
using namespace std;

void findOccurrences(int arr[], int size, int key, int i = 0){
    if(i==size){
        cout<<endl;
        return;
    }
    if(arr[i]==key){
        cout<<i<<" ";
    }
    return findOccurrences(arr, size, key, i+1);
}



int main(){
    int arr[11] = {1,2,3,3,5,5,3,6,7,8,9};
    findOccurrences(arr, 11, 5,0);
    return 0;
}