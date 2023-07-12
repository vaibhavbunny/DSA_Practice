#include<iostream>
#include<algorithm>
class List;

class Node{
    int data;
public:
    Node* next; // pointer to acess the adress.
    // constructor.
    Node(int d):data (d),next(NULL){}
    // getter to acesss private data.
    int getData(){
        return data;
    }
    // destructor for Node Deletion.
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
    friend class List;
};

class List{
    Node* head;
    Node* tail;

    int searchHelper(Node* start,int key){
        // base case.
        if(start==NULL){
            return -1;
        }
        // value match
        if(start->data==key){
            return 0;
        }
        // rec case.
        int subidx = searchHelper(start->next,key);
        if(subidx==-1){
            return -1;
        }
        return subidx + 1;
    }
public:
    List():head(NULL),tail(NULL){} // whenever a new linkedlist is created it is going to be initialised with NULL.

    Node* Begin(){
        return head;
    }
    void push_front(int data){
        if(head==NULL){
            Node* n = new Node(data); // creating a new node for which memory is allocated dynamically.
            head = tail = n; // equating head and tail to be new node.
            return;
        }else{
            Node* n = new Node(data);
            n->next = head; //pointed towards the new nodes head.
            head = n;
        }
    }
    void push_back(int data){
        if(head==NULL){
            Node* n = new Node(data);
            n->next = head;
            head = tail = n;
        }else{
            Node* n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }
    void insert(int data,int pos){
        if(pos==0){
            push_front(data);
        }
        //otherwise
        Node* temp = head;
        for(int jump=1;jump<=pos-1;jump++){
            temp = temp->next;
        }

        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
    void pop_front(){
        Node* temp = head;// temporary creation of a node and copying it then moving the head pointer to next node and making the node of temp = NULL AND DELETING THE TEMP NODE.
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back(){
        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        Node* output = temp->next;
        temp->next = NULL;
        delete output;
    }
    void remove(int pos){
        int i=0;
        Node* temp = head;
        while(i!=pos-2){
            temp = temp->next;
            i++;
        }
        Node* output = temp->next;
        temp->next = output->next;
        output->next = NULL;
        delete output;
    }
    // searching in a linked_list.
    int search(int key){
        Node* temp = head;
        int idx = 0;

        while(head!=NULL){// NULL will be at the end of the Linked_List.
            if(temp->data==key){
                return idx;
            }
            idx++;
        }
        return -1;
    }// recursively searching a key in a linked_list.
    int linear_search(int key){
        return searchHelper(head,key);
    }
    // destructor for a Linked_List.
    ~List(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
    }
};