#include<iostream>
#include<climits>

using namespace std;
int buySellStock(int arr[], int n){
    int bestBuy = 0;
    int maxProf =0;
    for(int i =1; i<n; i++){
        int profit = arr[i] - arr[bestBuy];
        if(profit<0)bestBuy=i;
        maxProf= max(profit, maxProf);
    }
    return maxProf == 0 ? -1 : maxProf;
}
int main (){
    int arr[]= {7,1,1,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<buySellStock(arr, n);
}