#include<iostream>
#include<cstring>
using namespace std;

void toUpperCase(char arr[], int n){
    // 'a' = 97,  'A' = 65
    for(int i =0; i<n; i++){
        if(arr[i]>=97){
            arr[i] = arr[i]-32;
        }
    }
    cout<<arr<<endl;
    
}

void reverse(char arr[], int n){
    int st = 0, end = n-1;
    while(st<end){
        swap(arr[st], arr[end]);
        st++; end--;
    }
    cout<<arr<<endl;
}

bool isPalindrome(char arr[], int n){
    int st = 0, end = n-1;
    while(st<end){
        if(arr[st]!=arr[end]){
            cout<<"Not a Palindrome"<<endl;
            return false;
        }
        st++; end--;        
    }
    return true;

}

int main (){
    char arr[] = "maam";
    int n = strlen(arr);
    toUpperCase(arr, n);
    reverse(arr, n);
    cout<<isPalindrome(arr,n);
}