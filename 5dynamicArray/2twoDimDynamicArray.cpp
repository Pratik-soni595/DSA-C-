#include<iostream>
using namespace std;
int main(){
    int rows,cols;
    cin>>rows>>cols;
    int * *matrix = new int*[rows]; // creating a dynamic array of pointers of size 5
    for(int i =0; i<5; i++){
        matrix[i] = new int[cols]; // allocating the member pointers memrory of an array of 4 elements
    }
    return 0;
}