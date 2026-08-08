#include<iostream>
#include<climits>
using namespace std;

int trappingRainWater(int arr[], int n){
    int leftLargest[n];
    int rightLargest[n];
    int l = 0, r = 0;
    int i=0, j=n-1;
    while(i<n){
        leftLargest[i]=l;
        rightLargest[j]=r;

        if(arr[i]>l) l = arr[i];
        if(arr[j]>r) r = arr[j];

        i++;
        j--;
    }

    int trappedWater= 0;
    for(int i =0; i<n; i++){
        int currWater= min(leftLargest[i], rightLargest[i]) - arr[i];
        if(currWater>0) trappedWater+=currWater;    
    }
    return trappedWater;
}

int main() {
    int height[]={4,2,0,6,3,2,5};
    // int height[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(height)/sizeof(height[0]);
    cout<<trappingRainWater(height, n);
}