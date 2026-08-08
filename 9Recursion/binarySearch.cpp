#include <iostream>
using namespace std;
int binarySearch(int arr[], int target, int start, int end){
    int mid = start + (end-start)/2;
    if(arr[mid]==target) return mid;
    if(arr[mid]>target) {
        return binarySearch(arr, target, start, mid-1);
    }else{
        return binarySearch(arr, target, mid+1, end );
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int target = 9;
    cout<<binarySearch(arr,target, 0, 9);
    return 0;
}