#include <iostream>
#include <vector>
using namespace std;

void printSudoku(int sudoku[][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}



bool isSafe(int sudoku[9][9], int row, int col, int dig){
    for(int i =0; i<9; i++){
        if(dig == sudoku[row][i]) return false; // for hz safety
        if(dig == sudoku[i][col]) return false; // for vertical safety
    }

    // safety in grid
    int sRow = (row/3)*3;
    int sCol = (col/3)*3;
    for(int i = sRow; i<sRow+3; i++){
        for(int j = sCol; j<sCol+3; j++){
            if(sudoku[i][j]==dig) return false;
        }
    }

    return true;
}


bool sudokuSolver(int sudoku[9][9], int row =0, int col=0){
    if(row == 9) {
        printSudoku(sudoku);
        return true;
    }
    int nextRow = row;
    int nextCol = col+1;
    if(nextCol==9) {
        nextRow = row+1;
        nextCol = 0;
    }

    if(!sudoku[row][col]){
        for(int dig=1; dig<=9; dig++){
            if(isSafe(sudoku, row, col, dig)){
                sudoku[row][col]=dig;
                if(sudokuSolver(sudoku, nextRow, nextCol)){
                    return true;
                }
                sudoku[row][col]=0;
            }
        }
        return false;
    }

    if(sudoku[row][col]!=0){
        return sudokuSolver(sudoku, nextRow, nextCol);
    }
}

int main (){
    int sudoku[9][9] = {
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {4, 9, 0, 1, 5, 7, 0, 0, 2},
        {0, 0, 3, 0, 0, 4, 1, 9, 0},
        {1, 8, 5, 0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {9, 6, 0, 4, 0, 5, 3, 0, 0},
        {0, 3, 0, 0, 7, 2, 0, 0, 4},
        {0, 4, 9, 0, 3, 0, 0, 5, 7},
        {8, 2, 7, 0, 0, 9, 0, 1, 3}
    };

    sudokuSolver(sudoku);
}