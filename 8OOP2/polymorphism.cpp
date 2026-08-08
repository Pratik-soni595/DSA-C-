#include <iostream>
using namespace std;


// Polymorphism is the ability of objects to take multiple forms  or behave in different manner depending on the context in which they are used

// constructor overloading is an example of polymorphism


// compile time polymorphism
// run time polymorphism


// compile time:

    // function overloading  - 

class Print {
public:
    void show(int num){
        cout<<num<<endl;
    }
    void show(string s){
        cout<<s<<endl;
    }
};

    // operator Overloading
class Complex{
    int real;
    int img;
public:
    Complex(int r, int i){
        real = r;
        img = i;
    }
    void show(){
        cout<< real<<" + "<<img<<"i\n";
    }

    Complex operator + (Complex obj){
        int real = this->real + obj.real;
        int img = this->img + obj.img;
        Complex res (real, img);
        return res;
    }
    
};



// Runtime Polymorphism

    // function overriding: Parent and child class both contain same method with different implementation. The parent class function is said to be overridden

    // virtual function: it is  a member function that you expect to be redifined in the derived class

class Parent{
public:
    virtual void sayHello(){
        cout<<"Parent Hello";
    }
};

class Child : public Parent{
public:
    void sayHello(){ // overridding
        cout<<"Child Hello";
    }
};


// abstract classes and pure virtual function



int main(){
    // Print p1;
    // p1.show(34);
    // p1.show("Pratik");



    // Complex c1(4,3);
    // Complex c2(2,1);
    // c1.show();
    // c2.show();
    // Complex c3 = c1+c2;
    // c3.show();



    // Parent *ptr;
    // Child ch1;
    // ptr = &ch1; //runtime binding
    // ptr->sayHello(); //child class' implementation will be used because of overridding after dynamic/runtime binding



    
    
    return 0;
    
}