#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char,Node*> m;
    bool isTerminal;
// public:
    Node(char data){
        this->data = data;
        isTerminal = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node('\0'); // whenever we will call Trie class it will be automatically root set to NULL.
    }
    // insertion.
    void insert(string word){
        Node* temp = root;
        for(char ch : word){
            if(temp->m.count(ch)==0){
                Node* n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    // searching.
    bool search(string word){
        Node* temp = root;
        for(char ch : word){
            if(temp->m.count(ch)==0){
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};