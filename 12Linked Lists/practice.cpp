#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
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
    ~List(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
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

int size(Node* head){
    int size = 0;
    Node* prev = head;
    while(prev != NULL){
        size++;
        prev = prev->next;
    }
    return size;
}

void removeFromEnd(int n, Node* head){
    Node* prev = head;
    for(int i = 1; i<size(head)-n; i++){
        prev = prev->next;
    }
    Node* temp = prev->next;
    prev -> next = temp->next;
    temp->next = NULL;
    delete temp;
}

Node* intersection(Node* head1, Node* head2){
    int s1 = size(head1);
    int s2 = size(head2);

    Node* i1 = head1, *i2 = head2;
    if(s1 >= s2){
        int diff = s1-s2;
        for(int i = 1; i<= diff; i++){
            i1 = i1->next;
        }
    }else{
        int diff = s2-s1;
        for(int i = 1; i<= diff; i++){
            i2 = i2->next;
        }
    }

    while(i1&& i2){
        if(i1 == i2){
            cout<<"Intersection found at pointer : i1"<<endl<<"Data : "<<i1->data<<endl;
            return i1;
        }else{
            i1 = i1->next;
            i2 = i2->next;
        }
    }
}

void deleteNode(int m, int n, Node* head){
    Node* temp = head;
    int i = 1;
    while(temp){
        if(i%m == 0){
            Node* delTemp = NULL;
            for(int j = 0; j<n; j++){
                delTemp = temp->next;
                if(!delTemp){
                    return;
                }
                temp->next = delTemp->next;
                delTemp->next = NULL;
                delete delTemp;
            }
        }
        temp= temp->next;
        i++;
    }
}



void swapNode(int x, int y, Node* &head){
    Node* temp = head;
    Node* xPrev = NULL, * yPrev = NULL;
    Node* xNode = NULL, * yNode = NULL;

    if(x==y) return;

    // checking if any of the key lies on head node
    if(temp->data == x){
        xNode = temp;
    }else if(temp->data  == y){
        yNode = temp;
    }

    while(temp->next){
        if(temp->next->data == x && !xNode){
            xPrev = temp;
            xNode = temp->next;
        }else if(temp->next->data  == y && !yNode){
            yPrev = temp;
            yNode = temp->next;
        }
        temp = temp->next;
    }

    if(!xNode || !yNode){
        return;
    }else if(xNode == head){
        Node* xNext = xNode->next;
        yPrev->next = xNode;
        xNode->next = yNode->next;
        yNode->next = xNext;
        head = yNode;
    }else if(yNode == head){
        Node* yNext = yNode->next;
        xPrev->next = yNode;
        yNode->next = xNode->next;
        xNode->next = yNext;
        head = xNode;
    }else{
        xPrev->next = yNode;
        yPrev->next = xNode;
        Node* yNext = yNode->next;
        yNode->next = xNode->next;
        xNode->next = yNext;
    }
}



void oddEven(Node* &head){
    int n = size(head);
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }

    Node* temp = head;
    Node* prev = head;
    for(int i = 0; i<n; i++){
        if(temp->data %2 != 0){
            if(temp == head){
                head = temp->next;
                tail->next = temp;
                tail = temp;
                temp->next = NULL;
                temp = head;
            }else{
                prev->next = temp->next;
                temp->next = NULL;
                tail->next = temp;
                tail = temp;
                temp = prev->next;
            }
        }else{
            prev = temp;
            temp = temp->next;        }
    }
}



int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);

    ll.printList();

    swapNode(2, 8, ll.head);
    ll.printList();
    
}