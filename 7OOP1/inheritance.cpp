#include<iostream>
#include<string>

using namespace std;


class Animal{
public:
    string color;
    void eat(){
        cout<<"eats\n";
    }
    void breathe(){
        cout<<"breathes\n";
    }
};


// single-inheritance
class Mammal : public Animal{
public:
    string bloodType;
    Mammal(){
        this->bloodType = "warm";
    }
};


// Multi-level inheritance
class Dog : public Mammal{
public:
    void tailWag(){
        cout<<"A dog wags its tail\n";
    }
};



// Single inheritance:
class Fish : public Animal{  // when we don't write access modifier while inheritance, it is private by default 
public:
    int fins;
    void swims(){
        cout<<"swims\n";
    }
};




// multiple inheritance 
class Teacher {
public:
    int salary;
    string subject;
};

class Student{
public: 
    int rollno;
    float cgpa;
};

class TA : public Teacher, public Student{
public:
    string name;
    
};

int main (){
    // Dog d1;

    // d1.eat();
    // d1.breathe();
    // d1.tailWag();

    TA ta1;
    ta1.name = "Pratik Soni";
    ta1.subject = "C++";
    ta1.cgpa = 9.1;

    cout<< ta1.name<<endl;
    cout<< ta1.subject<<endl;
    cout<< ta1.cgpa<<endl;

    return 0;
}