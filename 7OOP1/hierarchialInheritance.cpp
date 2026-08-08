#include <iostream>
using namespace std;



// Hierarchial inheritance
class Animal{ // parent class
public:
    void eat(){
        cout<<"I am eating";
    }
    void breathe(){
        cout<<"I can breathe";
    }
};

class Bird : public Animal{ // child class
public: 
    void fly(){
        cout<<"I can fly";
    }
};

class Fish : public Animal{ // child class 
public: 
    void swim(){
        cout<<"I can swim";
    }
};

class Mammal : public Animal{ // child class
public: 
    void Walk(){
        cout<<"I can walk";
    }
};

int main (){

}
