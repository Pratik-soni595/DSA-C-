#include<iostream>
#include<climits>
using namespace std;
int maxSubArr(int arr[], int n){
    int ans = INT_MIN;
    for( int st=0; st<n; st++)
    {
        int sum =0;
        for(int end = st; end<n; end++)
        {
            sum+=arr[end];
            ans = max(ans, sum);
            cout<<sum<<" "<< ans<<", ";
        }
        cout<<endl;
    }
    return ans;
}
int main(){
    int arr[]={2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    // st and end index of a subarrays of an arrays
    // for( int st=0; st<n; st++)
    // {
    //     for(int end = st; end<n; end++)
    //     {
    //         cout<<"(St : "<<st<<" ";
    //         cout<<"End: "<<end<<" )  ";
    //     }
    //     cout<<endl;
    // }
    int mSAS = maxSubArr(arr, n);
    cout<<mSAS;
}