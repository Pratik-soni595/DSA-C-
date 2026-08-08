#include <iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start-1;
    
    for(int j = start; j<end; j++){
        if(arr[j]<=pivot){
            swap(arr[j], arr[++i]);
        }
    }
    swap(arr[++i],arr[end]);
    return i;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void quickSort(int arr[], int st, int end){
    if(st>=end) return;
    int pivotIdx = partition(arr, st, end);

    quickSort(arr, st, pivotIdx-1 ); // left half
    quickSort(arr, pivotIdx+1, end ); // right half
}

int main(){
    int arr[] = {6,3,7,5,2,4};
    int n= 6;
    quickSort(arr, 0, n-1);
    printArray(arr, n); 
    return 0; 
}