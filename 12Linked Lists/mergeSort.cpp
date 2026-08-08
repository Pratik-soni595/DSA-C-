#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        next = NULL;
    }
};

class List{
public:
    Node* head;
    Node* tail;
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val); // we create this node dynamically so that the node is not deleted after the execution of the method
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;  
        }
        cout<<"NULL"<<endl;
    }

    void insert(int val, int pos){
        Node* temp = head;
        Node* newNode = new Node(val);
        if(pos == 0){
            push_front(val);
            return;
        }
        for(int count = 0; count<pos-1; count++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next !=tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int helper(Node* temp, int key){
        if(temp == NULL){
            return -1;
        }
        if(temp->data == key){
            return 0;
        }
        int idx = helper(temp->next, key);
        if(idx == -1) return -1;
        else return idx+1;
    }
    
    int searchRec(int key){
        return helper(head, key);
    }

    void reverse(Node* curr, Node* prev = nullptr){
        if(curr == NULL) {
            tail = head;
            head = prev;
            return;
        }
        Node* next = curr->next;
        curr->next = prev;
        reverse(next, curr);
    }
    void reverseLl(){
        reverse(head);
    }

    int size(){
        int size = 0;
        Node* prev = head;
        while(prev != NULL){
            size++;
            prev = prev->next;
        }
        return size;
    }
    
    void removeFromEnd(int n){
        Node* prev = head;
        for(int i = 1; i<size()-n; i++){
            prev = prev->next;
        }
        Node* temp = prev->next;
        prev -> next = temp->next;
        temp->next = NULL;
        delete temp;
    }

    void detectLoopAndRemove(){
        Node* slow = head;
        Node* fast = head;
        int d = 0;
        bool exists = false;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            d++;
            if(slow == fast){
                cout<<"cycle exists"<<endl;
                cout<<"cycle length : "<<d<<endl;
                exists = true;
                break ;
            }
        }
        if(!exists){
            cout<<"cycle doesn't exist"<<endl;
            return;
        }
        
        // now slow and fast pointers point to the same node
        // we now reset slow pointer to head and fast remains as it is
        slow = head;
        if(fast == slow){
            while(fast->next!=slow){
                fast= fast->next;
            }
            fast->next = NULL;
            cout<<"Cycle Removed"<<endl;
            return;
        } else {
            Node* prev = fast;
            while(slow!= fast){
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL;
            cout<<"Cycle Removed"<<endl;
            
            return;
        }
        
        
    }


};

Node* splitAtMid(Node* head){
    Node* slow, * fast, * prev = NULL;
    slow = fast = head;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // now slow points at the mid, and prev at the node previous to the middle node
    if(prev != NULL){
        prev->next = NULL;
    }
    return slow;
}   

Node* merge(Node* leftHead, Node* rightHead){
    Node* i1 = leftHead, * i2 = rightHead;
    List temp;
    
    while(i1 && i2){
        if(i1->data <= i2->data){
            temp.push_back(i1->data);
            i1 = i1->next;
        }else{
            temp.push_back(i2->data);
            i2 = i2->next;
        }
    }
    while(i1){
        temp.push_back(i1->data);
        i1 = i1->next;
    }
    while(i2){
        temp.push_back(i2->data);
        i2 = i2->next;
    }
        
    return temp.head;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* rightHead = splitAtMid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
    
}


int main(){
    List ll;
    ll.push_back(4);
    ll.push_back(1);
    ll.push_back(2);
    ll.printList();
    Node* newHead = mergeSort(ll.head);
    List newList;
    newList.head = newHead;
    newList.printList();
    return 0;
}