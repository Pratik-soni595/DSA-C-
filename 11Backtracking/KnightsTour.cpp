#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<int>>& board, int n){
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

vector<vector<int>> boardMaker(int n, int init){
    vector<vector<int>> board(n,vector<int>(n,init));
    return board;
}

bool isValid(int n, int i, int j){
    if(i<0||j<0||i>=n||j>=n) return false;
    else return true;
}

int checkOpenWays(int n, int i, int j, vector<vector<int>>& visited){
    int ans = 0;
    int dr[] = {-2,-2,2,2,1,1,-1,-1};
    int dc[] = {1,-1,1,-1,2,-2,2,-2};

    for (int k = 0; k < 8; k++) {
        int ni = i + dr[k];
        int nj = j + dc[k];

        if (isValid(n, ni, nj) && !visited[ni][nj])
            ans++;
    }
    return ans;
}

bool tour(int n, int i, int j, int count, vector<vector<int>>& board , vector<vector<int>>& visited ){
    cout<<count<<endl;
    visited[i][j]=1;
    board[i][j] = count;
    if(count == n*n - 1){
        printBoard(board, n);
        return true;
    }

    int dr[] = {-2,-2,2,2,1,1,-1,-1};
    int dc[] = {1,-1,1,-1,2,-2,2,-2};

    for (int k = 0; k < 8; k++) {
        int ni = i + dr[k];
        int nj = j + dc[k];

        if (isValid(n, ni, nj) && !visited[ni][nj]){
            if(tour(n, ni, nj, count+1, board, visited)) return true;
        }
    }
    visited[i][j]=0;
    board[i][j] = -1;
    return false;

}

int main(){
    vector<vector<int>> visited = boardMaker(8,0);
    vector<vector<int>> board = boardMaker(8,-1);

    bool exists = tour(8,0,0,0,board,visited);
    if(!exists) cout<< "The solution doesn't exist";
}