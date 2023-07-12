#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Node{
public:
    int key;
    Node *left;
    Node *right;

    // constructor.
    Node(int key){
        this->key = key;
        left = right = NULL;
    }
};

Node* insert(Node*root,int key){
    // base case.
    if(root==NULL){
        return new Node(key);
    }
    // rec case.
    if(key < root->key){
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right, key);
    }
    return root;
}
void printInorder(Node*root){
    if(root==NULL){
        return;
    }
    // left,root,right.
    printInorder(root->left);
    cout<<root->key<<",";
    printInorder(root->right);
}

bool search(Node* root,int key){
    // homework.
    // base case.
    if(root==NULL){
        return false;
    }
    if(root->key==key){
        return true;
    }
    if(key < root->key){
        return search(root->left,key);
    }
    return search(root->right,key);
}

Node* findMin(Node*root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
// deletion of a Node in BST.
Node* remove(Node*root,int key){
        if(root==NULL){
            return NULL;
        }
        else if(key < root->key){
            root->left = remove(root->left,key);
        }else if(key > root->key){
            root->right = remove(root->right,key);
        }else{
            // actual deletion. when the current node matches the node to be removed.
            // 1- leaf node.
            if(root->left==NULL and root->right==NULL){
                delete root;
                root = NULL;
            }
            // single child.
            else if(root->left==NULL){
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right==NULL){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            // double child.
            else{
                Node* temp = findMin(root->right);
                root->key = temp->key;
                root->right = remove(root->right,temp->key);
            }
        }
        return root;
}

void printInRange(Node*root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->key<=k2 and root->key>=k1){
        // call on both sides.
        printInRange(root->left,k1,k2);
        cout<<root->key<<",";
        printInRange(root->right,k1,k2);
    }else if(root->key < k1){
        printInRange(root->right,k1,k2);
    }else{
        // root->key > k2.
        printInRange(root->left,k1,k2);
    }
}

void printpath2leaf(Node*root,vector<int> &path){
    // base case.
    if(root==NULL){
        return;
    }
    // leaf node reached return the path.
    else if(root->left==NULL and root->right==NULL){
        for(int node:path){
            cout<<node<<"->";
        }
        cout<<root->key;
        cout<<endl;
        return;
    }
    // rec case and backtracking.
    path.push_back(root->key);
    printpath2leaf(root->left,path);
    printpath2leaf(root->right,path);
    // backtracking.
    path.pop_back();
}

int main(){
    Node * root = NULL;
    int a[] = {8,3,10,1,6,14,4,7,13};
    for(int i=0;i<9;i++){
        root = insert(root,a[i]);
    }
    printInorder(root);
    cout<<endl;
    // printInRange(root,6,13);
    vector<int> path;
    printpath2leaf(root,path);
    return 0;
}