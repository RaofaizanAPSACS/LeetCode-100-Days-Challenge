/*
Problem link: 
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

Problem:
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin 
of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the 
only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int d){
        val = d;
        next = NULL;
    }
};

void insert(int val,Node* head){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

int pairSum(Node* head) {
    Node* temp = head;
    vector<int> values;
    int max = INT_MIN;
    while(temp){
        values.push_back(temp->val);
        temp = temp->next;
    }
    for(int i=0;i<(values.size()/2)-1;i++){
        if(values[i]+values[values.size()-1-i] > max)
            max = values[i]+values[values.size()-1-i];
    }
    return max;
}

int main(){   
    Node* head = new Node(5);
    insert(4,head);
    insert(2,head);
    insert(1,head);
    cout<<pairSum(head);
	return 0;
}