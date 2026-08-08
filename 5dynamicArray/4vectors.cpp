#include <iostream>
#include <vector>

using namespace std;

vector<int> pairSum (vector<int> arr, int target){
    int st = 0, end = arr.size()-1;
    vector<int> ans;
    while(st<end){
        if(arr[st]+arr[end] == target) {
           ans.push_back(st);
           ans.push_back(end);
           return ans;
        }else if(arr[st]+arr[end] > target){
            end--;
        }else{
            st++;
        }
    }
}


int maxArea(vector<int>& height) {
    int st = 0, end = height.size()-1;
    int maxWater = 0;
    while (st<end){
        int currWater = min(height[st],height[end]) * (end-st);
        maxWater = max(maxWater, currWater);
        if(height[st]<height[end]){
            st++;
        }else{
            end--;
        }
    }
    return maxWater;
}

int main(){
    // vectors are also called sequence containers
    // pair sum
    // vector<int> arr = {1,2,4,7,9};
    // vector<int> pair= pairSum(arr, 16);
    // for(int i =0; i<pair.size(); i++){
    //     cout<<pair[i]<<", ";
    // }
    // cout<<endl;


    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    
    
}