#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

template<class T>
class Stack{
    list<T> ll;
public:
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    T top (){
        return ll.front();
    }
    bool isEmpty(){
        return ll.size()==0;
    }
};