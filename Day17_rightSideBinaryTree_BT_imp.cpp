/*
Problem link: 
https://leetcode.com/problems/binary-tree-right-side-view/

Problem:
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

 
Algorithm or Approach :  Used level order traversal and stored each level last element

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
int height(Node* node){
    if (node == NULL)
        return 0;
    return max(height(node->left), height(node->right))+1;
}
void levelOrder(Node* node,int level,int &res){
    if(node == NULL)
        return;
    if(level == 1)
        res = node->val;
    levelOrder(node->left,level-1,res);
    levelOrder(node->right,level-1,res);
}
vector<int> rightSideView(Node* root) {
    vector<int> res;
    Node* temp = root;
    int val,h = height(temp);
    for(int i=1;i<=h;i++){
        levelOrder(root,i,val);
        res.push_back(val);
    }
    return res;
}

int main(){ 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    // root->right->right = new Node(4);
    vector<int> res = rightSideView(root);
    for(auto x: res)
        cout<<x<<" ";
    return 0;
}