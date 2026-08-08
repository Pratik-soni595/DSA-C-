#include <iostream>
using namespace std;

// friend functions and classes of a class are those classes who have access to the private and protected attributes of the class

class A{
    int secret = 90;
    friend class fr;
    friend void showSecret(A &obj);
};

class fr{
    void showSecret(A &obj){
        cout<<obj.secret;
    }
};

void showSecret(A &obj){
    cout<<obj.secret;
}


int main(){

}