#include<iostream>
using namespace std;

void transpose (int arr[][3], int n, int m){
    // this function will return the pointer to the first row of the transposed matrix
    int tArr[m][n];
    for(int j=0; j<n; j++){
        for(int i =0; i<m; i++){
            tArr[i][j] = arr[j][i];
        }
    }

    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            cout<<tArr[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int arr[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    transpose(arr, 2,3);
    return 0;
}