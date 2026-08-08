#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Stack {
    vector<T> vec;
public:
    void push(T val){
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty";
            return;
        }
        vec.pop_back();
    }

    T top(){
        // if(isEmpty()){
        //     cout<<"Stack is empty";
        //     return -1;
        // }
        return vec[vec.size()-1];
    }

    bool isEmpty(){
        if(vec.size() == 0){
            return true;
        }else{
            return false;
        }
    }
};

int main (){
    Stack<int>  s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}