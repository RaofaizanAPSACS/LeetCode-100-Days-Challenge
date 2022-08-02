/*
Problem link: 
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Problem:
Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v){
            val = v;
            left = NULL;
            right = NULL;
        }
};
Node* insert(Node* head, int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = newNode;
    }
    return head;
}
void preOrder(Node* root){
    if(root == NULL)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void preOrder2(Node* root, vector<int> &val){
    if(root == NULL)
        return;
    val.push_back(root->val);
    preOrder2(root->left, val);
    preOrder2(root->right, val);
}

void flatten(Node* root){
    vector<int> val;
    preOrder2(root,val);
    Node* newNode = NULL;
    for(int i=0;i<val.size();i++){
        newNode = insert(newNode, val[i]);
    }
    newNode = newNode->right;
    root->left = NULL;
    root->right = NULL;
    root->right = newNode;
    preOrder(root);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    flatten(root);
    return 0;
    
}