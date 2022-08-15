/*
Problem link: 
https://leetcode.com/problems/binary-search-tree-iterator/

Problem:
Implement the BSTIterator class that represents an iterator over the in-order traversal of a 
binary search tree (BST):
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

void inorder(Node* root, vector<int> &itr){
    if(root == NULL)
        return;
    inorder(root->left,itr);
    itr.push_back(root->val);
    inorder(root->right,itr);
}

class BSTIterator {
    vector<int> itr;
    int count;
public:
    BSTIterator(Node* root) {
        inorder(root,itr);
        count = -1;
    }
    int next() {
            return itr[++count];
    }
    bool hasNext() {
        if(count + 1 < itr.size())
            return true;
        else return false;
    }
};
int main(){   
    Node* root=NULL;
    root = insert(root,7);
    insert(root,3);
    insert(root,15);
    insert(root,9);
    insert(root,20);
    
    BSTIterator *obj = new BSTIterator(root);
    cout<<obj->next();
    cout<<obj->next();
    cout<<obj->next();
    cout<<obj->hasNext();
	return 0;
}