/*
Problem link: 
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

Problem:
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that 
every key of the original BST is changed to the original key plus the sum of all keys greater 
than the original key in BST

 
Algorithm or Approach :  Inorder 

*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v){
            val = v;
            left = right = NULL;
        }
};


Node* insert(Node* root, int d){
    if(root == NULL){
        return new Node(d);      
    }
    if(d < root->val){
        root->left =  insert(root->left,d);
    }
    else{
        root->right =  insert(root->right,d);
    }
    return root;
}
void inOrder(Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}
Node* bstToGst(Node* root) {
    static int sum=0;
    if(root == NULL)
        return root;
    bstToGst(root->right);
    sum += root->val;
    root->val = sum;
    bstToGst(root->left);
    return root;
}
int main(){ 
    Node* root = NULL;
    root = insert(root,4);
    insert(root,1);
    insert(root,6);
    insert(root,0);
    insert(root,2);
    insert(root,5);
    insert(root,7);
    insert(root,3);
    insert(root,8);
    Node* newRoot = bstToGst(root);
    inOrder(newRoot);
    return 0;
}