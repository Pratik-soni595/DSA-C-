#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

void print (int arr[], int n){
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        bool isSwap = false; // this variable is to check if the array is already sorted
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
            isSwap = true;
        }
        if(!isSwap){
            cout<<"Array already sorted";
            return; // if the array is already sorted then there will be no swapping in any loop that means the value of isSwap remains false and hence we return;
        } 
    }
    print(arr, n);
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
    print(arr, n);
}


void insertionSort(int arr[], int n){
    for(int i =1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;
    }
    print(arr, n);
}


void countingSort(int arr[], int n){
    // use a frequency count of elements from min to max
    // it is used for small range of numbers
    // mostly used for positive no.
    int freq[100000] ={0}; //range
    int minVal = INT_MAX, maxVal = INT_MIN;
    
    // 1st step
    for(int i =0; i<n; i++){
        freq[arr[i]]++;
        minVal = min (minVal, arr[i]);
        maxVal = max (maxVal, arr[i]);
    }

    // 2nd step
    for(int i= minVal, j=0; i<=maxVal; i++){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
    print (arr, n);
}


int main(){
    int arr[]= {1,4,2,5,3};
    print(arr, 5);
    // bubbleSort(arr, 5);
    // selectionSort(arr, 5);
    // insertionSort(arr, 5);
    // countingSort(arr, 5);
    sort(arr, arr+5); // inbuilt function for sorting in ascending order
    print(arr, 5);
    sort(arr, arr+5, greater<int>()); // for descending order
    print(arr, 5);
}