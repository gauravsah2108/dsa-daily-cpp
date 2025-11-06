#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    /* data */
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class solution{
public:
    bool isMirror(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;

        return (t1->val , t2->val) && isMirror(t1->left,t2->right) && isMirror(t2->left,t1->right);
    }

    bool isSymmetric(TreeNode* root){
        if(!root) return true;

        return isMirror(root->left,root->right);
    }
};

TreeNode* newNode(int val){
    return new TreeNode(val);
}

int main(){

    solution sol;

    TreeNode *root1= newNode(1);
    root1->left=newNode(2);
    root1->right=newNode(2);
    root1->left->left=newNode(3);
    root1->left->right=newNode(4);
    root1->right->left=newNode(4);
    root1->right->right=newNode(3);

    cout<<"Is Symmetric ?"<< (sol.isSymmetric(root1)?"true":"false")<<endl;



    return 0;
}