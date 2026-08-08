#include <iostream>
#include <list>
#include <iterator> // iterators are objects that allows us to traverse through the elements of a container
// we use iterators somewhat like pointersf

using namespace std;



void printList(list<int> ll){
    list<int>:: iterator itr;
    // ll.begin() returns the iterator to head node, ll.end() returns iterator to tail->next node (NULL)
    for(itr = ll.begin(); itr!=ll.end(); itr++){ 
        cout<<*itr<<" -> ";
    }
    cout<<"NULL"<<endl;
    return;
}



int main(){
    list<int> ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    printList(ll);

    cout<<"Head = "<<ll.front()<<endl;
    cout<<"Tail = "<<ll.back()<<endl;
}