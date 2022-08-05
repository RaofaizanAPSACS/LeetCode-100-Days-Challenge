/*
Problem link: 
https://leetcode.com/problems/binary-tree-paths/

Problem:
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Algorithm or Approach :  PreOrder

*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:    
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};
void preOrder(Node* root,vector<string> &ans,vector<int> v){
    if(root == NULL)
        return;
    if(root->left == NULL and root->right == NULL){
        string str="";
        for(int i=0;i<v.size();i++){
            str += to_string(v[i]) + "->";
        }
        str += to_string(root->val);
        ans.push_back(str);
        return;
    }
    v.push_back(root->val);
    preOrder(root->left,ans,v);
    preOrder(root->right,ans,v);
    v.pop_back();
}
vector<string> binaryTreePaths(Node* root){
    vector<string> ans;
    vector<int> v;
    preOrder(root,ans,v);
    return ans;
}
int main(){ 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    vector<string> ans = binaryTreePaths(root);
    for(auto x: ans)
        cout<<x<<" ";

    return 0;
}