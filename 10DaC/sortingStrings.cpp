#include<iostream>
#include<string>
using namespace std;

void merge(string arr[], int st, int end, int mid){
    string temp[end-st +1];
    int i = st;
    int j = mid+1;
    int count = 0;
    while(i<=mid && j<= end){
        if(arr[i]<=arr[j]){
            temp[count++] = arr[i++];
        }else{
            temp[count++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[count++] = arr[i++];
    }
    while(j<=end){
        temp[count++] = arr[j++];
    }

    count = 0;
    for(int k = st; k<=end; k++){
        arr[k] = temp[count++];
    }
}

void sort (string arr[], int st, int end){
    if(st==end) return;
    
    int mid = st+ (end-st)/2;
    sort(arr, st, mid);
    sort(arr, mid+1, end);

    merge(arr, st, end, mid);
}

void printArray(string arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    string arr[] = {"sun", "earth", "mars", "mercury"};
    printArray(arr, 4);
    cout<<endl;
    sort(arr, 0, 3);
    printArray(arr, 4);

    return 0;
}