#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int> vec, int target, int i =0){
    if(i==vec.size()){
        return -1;
    } 
    if(vec[i]==target){
        return i;
    }
    return firstOccurrence(vec, target, i+1);
}

int lastOccurrence(vector<int> vec, int target, int i =0){
    if(i == vec.size()) return -1;

    int temp = lastOccurrence(vec, target, i+1);
    if (temp == -1 && vec[i] == target){
        return i;        
    }
    return temp;
}


int main(){
    vector<int> arr = {1,2,3,4,5,3,5};
    int target = 3;
    cout<<firstOccurrence(arr, target)<<endl;
    cout<<lastOccurrence(arr, target);
}