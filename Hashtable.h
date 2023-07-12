// hashtable file.h
#include<iostream>
#include<string>
using namespace std;
template<typename T>

class Node{
public:
    string key;
    T value;
    Node* next;

    // constructor.
    Node(string key,T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    // destructor.
    ~Node(){
        if(next!=NULL){ // destructor call kelyawer pahliyanda tyacha next jr non null asel tr tyala delete kr.
            delete next;
        }
    }
};

template<typename T>
class Hashtable{
    Node<T> **table;
    int cs;
    int ts;
    
    int hashFn(string key){

        int idx = 0;
        int power = 1;
        for(auto ch : key){
            idx = (idx + ch*power)%ts; // modulo is taken in every step to avoid overflow.
            power = (power*29)%ts;
        }
        return idx;
    }
    void rehash(){
        // save the ptr to the oldtable and we will do insertion in the newtable.
        Node<T> **oldtable = table; // oldtable ptr will point towards existing ptr and existing will point towards new.
        int oldTs = ts;
        // increase the table size.
        ts = 2*ts+1;
        table = new Node<T>*[2*ts+1]; // new hashtable is created with.
        // each of the Head ptrs in new table are initialised with null so that they are not garbage.
        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }
        // copy elements from oldtable to new table.
        for(int i=0;i<oldTs;i++){
            Node<T> *temp = oldtable[i];
            while(temp!=NULL){
                string key = temp->key;
                T value = temp->value;
                // happens in the new table.
                insert(key,value);
                temp = temp->next;
            }
            // destroy the ith node.
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete [] oldtable;
    }
public:
    Hashtable(int default_size=7){
        cs = 0;
        ts = default_size;
        table = new Node<T>*[ts]; // *[ts] actually tells us ki utne number of new node bnaye gye hai.

        // we dont want ith head to be garbage.
        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }
    }
    void insert(string key,T value){
        int idx = hashFn(key);

        Node<T>* n = new Node<T>(key,value);
        // insertion is always at the head of the linked list. to amek sure it is or O(1);
        n->next = table[idx];
        table[idx] = n;
        cs++;

        float load_factor = cs/float(ts);
        if(load_factor > 0.7){
            rehash();
        }
    }
    T* search(string key){
        int idx = hashFn(key);

        Node<T> *temp = table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }
    void erase(string key) {
        int idx = hashFn(key);
        Node<T>* temp = table[idx];
        Node<T>* prev = nullptr;

        while (temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            // Key not found, handle the error condition.
            return;
        }
        if (prev == nullptr) {
            // The node to be deleted is the first node.
            table[idx] = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
    // supercool functionality of operator [] overloading.

    T& operator[] (string key){
        // return the value.
        // if key is not found then create a new node and return.
        // return the existing node.
        T* valuefound = search(key);
        if(valuefound==NULL){
            T object;
            insert(key,object);
            valuefound = search(key);
        }
        return *valuefound;
    }
    void print(){
        for(int i=0;i<ts;i++){
            cout<<"Bucket"<<i<<"->";

            Node<T> *temp = table[i];
            while(table[i]!=NULL){
                cout<<temp->key<<"->";
                temp = temp->next;
            }cout<<"\n";
        }
    }
};