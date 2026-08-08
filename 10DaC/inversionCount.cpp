#include<iostream>
#include<vector>

using namespace std;


int merge (int arr[], int st, int end, int mid) {
    int i = st, j = mid+1;
    int icount =0;

    vector<int> temp;

    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j++]);
            icount+= mid-i+1; //increasing the inversion count whenever the right half element is smaller than any left half element
        }else{
            temp.push_back(arr[i++]);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }

    for(int k = st, x =0; k<=end; k++, x++){
        arr[k] = temp[x];
    }

    return icount;
}


int inversionCount(int arr[], int st, int end){
    // base case
    if(st == end ) return 0;
    
    int mid = st+ (end-st)/2;
    int left = inversionCount(arr, st, mid);
    int right = inversionCount(arr, mid+1, end);
    
    int mergeCount =  merge(arr, st, end, mid);

    int ans = left+right+mergeCount;
}


int main(){
    int arr[] = {2,4,1,3,5};
    cout<<inversionCount(arr, 0, 4);
}