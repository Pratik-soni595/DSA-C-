#include<iostream>
using namespace std;

int search(int arr[], int st, int end, int target){
    if(st>end) return -1;

    
    int mid = st + (end-st)/2;
    if(arr[mid] == target){
        return mid;
    } 

    // checking if mid is on line 1 or line 2

    if(arr[st]<arr[mid]){// then mid is on line 1
        if(arr[st]<=target && target<arr[mid]){// lies in left half
            return search(arr, st, mid-1, target);
        }else{ // lies in right half
            return search(arr, mid+1, end, target);
        }
    }else{ // mid is on line 2
        if(arr[mid]<target && target<=arr[end]){ // lies in right half
            return search(arr, mid+1, end, target);
        }else{ // lies in left half
            return search(arr, st, mid-1, target);
        }
    }
}

int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int target = 1;
    cout<<search(arr,0, 6, target);
}