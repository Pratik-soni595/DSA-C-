#include <iostream>
using namespace std;


void count(){
    static int counter = 0;
    counter++;
    cout<<counter<<endl;
}

class Example{
public:
    static int x;
};

int Example::x = 0;

int main(){
    count();
    count();
    count();

    Example e1;
    Example e2;
    Example e3;

}