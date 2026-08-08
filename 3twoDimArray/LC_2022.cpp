#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> mat, int m, int n){
    for(int i =0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}


vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    // m rows   n cols
    if(m*n != original.size()) return {};
    vector<vector<int>> ans(m, vector<int>(n));
    int row = 0;
    int col = 0;
    for(int i = 0; i<m*n; i++){
        int decider = (i+1)%n;
        if(decider==0){
            ans[row][col] = original[i];
            row++;
            col=0;
        }
        else{
            ans[row][col] = original[i];
            col++;
        }
    }
    return ans;
}

int main(){
    vector<int> og = {1,2,3,4,5,6,7,8,9};

    vector<vector<int>> mat = construct2DArray(og, 3, 3);
    printMatrix(mat, 3, 3);

    // vector<vector<int>> sample = {
    //     {  1,  2,  3,  4 },
    //     {  5,  6,  7,  8 },
    //     {  9, 10, 11, 12 }
    // };
    // printMatrix(sample, 3, 4);
}