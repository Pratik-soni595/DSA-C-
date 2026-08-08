#include<iostream> 
using namespace std;
int main(){
    int size;
    cin>>size;
    int *ptr = new int[size];// this the way to create a dynamic array, 
    // whenever we allocate memory dynamically we need to handle its deletion separately, because it is not allocated in stack memory, it is alocated in heap memory
    // we manage deletion using delete keyword
    delete [] ptr; // this de-allocates the memory from the ptr variable

    // Memory leak: it occurs when we as programmers forget to de-alocate the memory which was allocated dynamically, 
}