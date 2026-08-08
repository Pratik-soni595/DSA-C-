#include<iostream>
using namespace std;


// Abstraction means hiding unnecessary details and showing only the important parts
// access modifiers are one of the ways to implement abstraction


// abstract classes
// we don't create object of abstract classes, the only work of these classes is to act as a parent class for other classes
// we need to have atleast one pure virtual function

class Shape{  // this is an abstract class
public:
    virtual void draw() = 0; // pure virtual function or abstract function
};

class Circle : public Shape{
public: 
    void draw(){
        cout<<"draw circle\n";
    }
};

class Square : public Shape{
public: 
    void draw(){
        cout<<"draw square\n";
    }
};



int main(){
    Circle c1;
    Square s1;

    c1.draw();
    s1.draw();
}