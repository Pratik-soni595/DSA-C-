#include <iostream>
using namespace std;

class Student {
    // properties
    int id;
    string name;
    float cgpa;

public:
    //methods
    void getCgpa(){
        cout<<cgpa;
    }

    Student(int id, string name, float cgpa){
        cout<<"contructor was called";
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
    }
};



class Car{
public:
    string name;
    string color;
    Car(string name, string color){
        this->name = name;
        this->color = color;
    }
};


int main(){
    // Student s1(1, "Pratik", 7.51);

    Car c1("BMW", "Blue");
    Car c2(c1);
    cout<<c2.name<<endl;

    
}