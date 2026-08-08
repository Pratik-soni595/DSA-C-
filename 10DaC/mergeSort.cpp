#include<iostream>
using namespace std;

void merge(int arr[], int start, int end, int mid){
    int i = start;
    int j = mid+1;
    int temp [end-start+1];
    int count =0;
    while(i<=mid&& j<=end){
        if(arr[i]<arr[j]){
            temp[count] = arr[i++];
        }
        else {
            temp[count] = arr[j++];
        }
        count++;
    }

    while(i <= mid){
        temp[count++] = arr[i++];
    }

    while(j <= end){
        temp[count++] = arr[j++];
    }
    
    count =0;
    while(start<=end){
        arr[start++] = temp[count++];
    }
}

void mergeSort(int arr[], int start, int end){ //time complexity : O(nlogn), Space : O(n)
    if(start >=end){
        return;
    }
    int mid = start + ((end-start)/2);
    
    // divide
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    // conquer
    merge(arr, start, end, mid);
}


int main(){
    int arr[] = {6,3,7,5,2,4};
    int n= 6;
    mergeSort(arr, 0, n-1);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0; 
}