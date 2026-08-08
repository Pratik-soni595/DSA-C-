#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

class List{
public:
    Node* head;
    
    void pushFront(int data){
        Node* newNode = new Node;
        newNode->data = data;
        if(head==NULL){
            head = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }

        head->prev = newNode;
        head = newNode;
    }
    void pop_front(){
        if(head==NULL) return;
        else if(head->next == NULL){
            delete head;
            head = NULL;
        }
    }
};