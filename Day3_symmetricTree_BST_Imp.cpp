/*
Problem link: 
https://leetcode.com/problems/symmetric-tree/

Problem:
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Algorithm or Approach :  Used Inorder traversal to Check the postions(left,right) 
                         or values of the Nodes in BT

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
            left = right = NULL;
        }
};

void inorder(Node* root, vector<int> &arr,vector<char>& pos,char var){
    if(root == NULL)
        return;
    inorder(root->left,arr,pos,'l');
    arr.push_back(root->val);
    pos.push_back(var);
    inorder(root->right,arr,pos, 'r');
}

bool checkValues(vector<int>& val){
    for(int i=0,j=val.size()-1; i<val.size()/2 and j > val.size()/2;i++,j--){
        if(val[i] != val[j])
            return false;
    }
    return true;
}
bool checkPositions(vector<char>& p){
    for(int i=0,j=p.size()-1; i<p.size()/2 and j > p.size()/2;i++,j--){
        if(p[i] == p[j])
            return false;
    }
    return true;

}

bool isSymmetric(Node* root){
    vector<int> val;
    vector<char> pos;
    inorder(root,val,pos,'l');
    if(val.size()%2 == 0)
        return false;
    if(checkPositions(pos) and checkValues(val))
        return true;
    return false;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(2);
    // root->left->right = new Node(2);
    root->right->left = new Node(2);
    // root->right->right = new Node(2);

    cout<<isSymmetric(root);

    return 0;
    
}