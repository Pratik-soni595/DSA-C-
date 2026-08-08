#include <iostream>
using namespace std;

class Complex{
public:
    int real;
    int img;

    Complex operator - (Complex &obj){
        Complex ans(0,0);
        ans.real = this->real - obj.real;
        ans.img = this->img - obj.img;
        return ans;
    }

    void print(){
        cout<<this->real<<" + "<<this->img<<"i";
    }
    
    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }
};


class Person{
protected:
    string name;
    int age;

public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
protected:
    int studentId;

public:
    Student(string name, int age, int studentId) : Person(name, age){
        this->studentId = studentId;
    }

    void showDetails(){
        cout<<"Name : "<<this->name<<endl;
        cout<<"Age  : "<<this->age<<endl;
        cout<<"I'd  : "<<this->studentId<<endl;
    }
};

int main(){
    // Complex c1(0,6);
    // Complex c2(5,6);
    // Complex diff = c1-c2;
    // diff.print();

    Student s1 ("Pratik", 20, 204);
    s1.showDetails();
    
}