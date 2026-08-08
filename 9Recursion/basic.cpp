#include <iostream>
using namespace std;

// write a function using recursion to print no. from n to 1
void printNumInRev(int n){
    if(n ==1 ){ // base case
        cout<<"1, ";
        return;
    }
    cout<<n<<", "; // kaam
    printNumInRev(n-1);  // assumption
}


int sumOfN(int n){
    if( n == 1 ){
        return 1;
    }
    return n + sumOfN(n-1);
}


int main (){
    // printNumInRev(10);
    cout<<sumOfN(5);
}