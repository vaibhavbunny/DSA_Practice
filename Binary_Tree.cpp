#include<iostream>
#include<queue>
using namespace std;

// Input = 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// output = 1 2 4 5 7 3 6 (preorder)
// output(Inorder) = 4 2 7 5 1 3 6

class Node{
public:
    int data;
    Node* left;  // this indicates the use of adresss as an data.
    Node* right;

    Node(int d){
        data = d;
        right = left = NULL;
    }
};
// preorder build of root tree, right and left tree.
Node* BuildTree(){
    int d;cin>>d;

    if(d==-1){
        return NULL;
    }
    Node* n = new Node(d);
    n->left = BuildTree();
    n->right = BuildTree();
    return n;
}

void printPreorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<< root->data <<",";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printInorder(Node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<",";
    printInorder(root->right);
}
void printPostorder(Node* root){
    if(root==NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<",";
}
// expected ouput for level order traversal.
// 1
// 2 3
// 4 5 6
// 7 
// This is most interesting part.. go through this one.
// not working as well.
void levelorderPrint(Node* root){
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            // insert a new NULL for the next level.
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            q.pop();
            cout<<temp->data<<" ";

            if(root->left){
                q.push(root->left);
            }if(root->right){
                q.push(root->right);
            }
        }
    }
    return;
}
// level order build.
// 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1 
Node* levelorderBuild(){
    int d;cin>>d;
    Node* root = new Node(d);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        int c1, c2;
        cin>>c1>>c2;
        if(c1!=-1){
            current->left = new Node(c1);
            q.push(current->left);
        }if(c2!=-1){
            current->right = new Node(c2);
            q.push(current->right);
        }
    }
    return root;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right); // post order traversal inside the tree. left -> right -> root.

    return 1 + max(h1,h2);
}

int Diameter(Node* root){
    // base case.
    if(root==NULL){
        return 0;
    }
    // rec case.
    int h1 = height(root->left);
    int h2 = height(root->right);
    int d3 = h1 + h2;
    int d1 = Diameter(root->left);
    int d2 = Diameter(root->right);
    int d = max(d1,max(d2,d3));
    return d;
}
// -------optimized Diameter.
class HDpair{
public:
    int height;
    int diameter;
};

HDpair optDiameter(Node*root){
    HDpair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    HDpair left = optDiameter(root->left);
    HDpair right = optDiameter(root->right);

    p.height = max(left.height,right.height)+1;
    
    int D1 = left.height + right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;
    p.diameter = max(D1,max(D2,D3));
    return p;
    
}
int main(){
    Node* root = BuildTree();

    levelorderPrint(root);
    cout<<Diameter(root)<<endl;

   return 0;
}