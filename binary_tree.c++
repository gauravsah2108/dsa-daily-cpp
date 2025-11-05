#include <iostream>
using namespace std;

struct Node{ //defines a structure (like small class) to represent each tree node.
    /* data */
    int val;// the value store in the node.

    Node* left;//pointer to left child node
    Node* right;//pointer to right child node

    Node(int x):val(x), left(nullptr), right(nullptr) {}
    //it's contructor(special function called when you create a new node ).
    //val(x)-> initializes val x.
    //left(nullptr) and right(nullptr) -> set both child pointers to null intially(means no children).

};

Node* insert(Node* root, int x){// A function that inserts a new value x into binary search tree.
    //it returns then new root to the subtree (which may have chnaged)
    if(!root) return new Node(x);// if root is null , then create and return a new node woth value x.->base case for recursion
    if(x<root->val) root->left = insert(root->left,x);//if x is smaller , go into the left swubtree.recusively call insert on the left child
    else root->right = insert(root->right,x);
    return root; // always return the currnt node so the parent's pointer stays correct.

}

Node* FindMin(Node* node){
    while (node && node ->left)node=node->left;
    return node;
}

Node* remove(Node* root,int x){
    if(!root) return root;
    if(x<root->val) root->left = remove(root->left,x);
    else if(x>root->val) root->right=remove(root->right,x);
    else{
        if(!root->left){
            Node* r = root->right;
            delete root;
            return r;
        }
        else if(!root->right){
            Node* l= root->left;
            delete root;
            return l;
        }
        else{
            Node* succ=FindMin(root->right);
            root->val=succ->val;
            root->right=remove(root->right,succ->val);
        }
    }
    return root;
}

void inorder(Node* node){
    if(!node)return;
    inorder(node->left);
    cout<<node->val<<" ";
    inorder(node->right);
}

int  main(){
    Node* root =nullptr;
    int vals[]={8,3,10,1,6,14,4,7,13};
    for(int v: vals )root=insert(root,v);

    cout<<"Inorder (should be sorted): ";
    inorder(root);cout<<"\n";

    cout<<"Delete 3\n";
    root=remove(root,3);
    cout<<"Inorder After deletion : ";
    inorder(root);cout<<"\n";


    return 0;

}