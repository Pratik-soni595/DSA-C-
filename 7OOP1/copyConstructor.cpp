#include <iostream> 
using namespace std;

class Car {
public: 
    string model;
    string color;
    int *mileage;

    Car(string model, string color){
        this->model = model;
        this->color = color;
        mileage = new int; // dynamic allocation for pointer
        *mileage = 60;
    }
    Car(Car &original){
        this->model = original.model;
        this->color = original.color;
        // this->mileage = original.mileage; // if we do this way the address will get copied to the value of mileage key in the new object
        // this will create a shallow copy of the object
        
        mileage = new int;
        *mileage = *original.mileage;
    }
    ~Car(){
        cout<<"Object going out of scope"<<endl;
        if(mileage!=NULL){
            delete mileage; // this will delallocate the memory from the pointer, but will not delete the pointer variable, 
            mileage = NULL;
        }
    }
};

int main (){
    Car c1("alto", "maroon");
    Car c2(c1);
    cout<<c1.mileage<<endl;
    cout<<c2.mileage<<endl;
    *c2.mileage = 70;
    cout<<*c1.mileage<<endl;
    cout<<*c2.mileage<<endl;
    return 0;
}