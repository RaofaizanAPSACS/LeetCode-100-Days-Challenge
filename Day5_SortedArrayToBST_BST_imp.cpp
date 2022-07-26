/*
Problem link: 
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Problem:
Given an integer array nums where the elements are sorted in ascending order, 
convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which 
the depth of the two subtrees of every node never differs by more than one.

Algorithm or Approach :  Divide & Conquer Algorithm

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

void inorder(Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void divideConquer(vector<int> nums,int s, int e, Node *&root){
    if(s <= e){
        int mid = (s+e)/2;
        
        if(root == NULL)
            root = insert(root,nums[mid]);
        else 
            insert(root,nums[mid]);

        divideConquer(nums,s,mid-1, root);
        divideConquer(nums,mid+1,e, root);    
    }
}

Node* sortedArrayToBST(vector<int>& nums){
    Node* root = NULL;
    divideConquer(nums,0,nums.size()-1, root);
    return root;
}


int main(){
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-3);
    nums.push_back(0);
    nums.push_back(5);
    nums.push_back(9);
    Node* root = sortedArrayToBST(nums);
    inorder(root);
    return 0;
    
}