#include<iostream>
#include<vector>
using namespace std;



// 1 - unvisited
// 2 - visited
// 0 - blocked

int ratMaze(vector<vector<int>> &maze, int row, int col){
    int n = maze.size();
    if(row<0||col<0 || row==n||col==n) return 0;
    if(maze[row][col]==0 || maze[row][col] == 2) return 0;
    if(row==n-1&& col == n-1) return 1;

    maze[row][col] = 2; // visited
    int ans = (
        ratMaze(maze, row+1, col)+
        ratMaze(maze, row, col+1)+
        ratMaze(maze, row-1, col)+
        ratMaze(maze, row, col-1)
    );
    maze[row][col] = 1;
    return ans; 
}

int main (){
    vector<vector<int>> maze = {
        { 1, 0, 0, 0 },
        { 1, 1, 0, 1 },
        { 1, 1, 0, 0 },
        { 0, 1, 1, 1 }
    };
    cout<<ratMaze(maze, 0,0);

}