/*
Created : 19 July, 2022
Problem link: 
https://leetcode.com/problems/merge-two-sorted-lists/

Problem:
Given the two sorted singly linked list, the task is to merge the two lists such that the elements 
should be in sorted order after the merge.

Algorithm or Approach :  Two Fingers approach

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int v, Node* n){
            val = v;
            next = n;
        }
};

Node* insert(Node* head, int d){
    Node* newNode = new Node(d,NULL);
    if(head == NULL){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

// merge the two sorted linked list into the new merged sorted linked list
Node* merge(Node* head1, Node* head2){
        Node* temp1 = head1, *temp2 = head2,* head3 = NULL;
        while(temp1 != NULL and temp2 != NULL){
            if(temp1->val < temp2->val){
                head3 = insert(head3, temp1->val);
                temp1 = temp1->next;
            }
            else if(temp2->val < temp1->val){
                head3 = insert(head3, temp2->val);
                temp2 = temp2->next;
            }
            else{
                head3 = insert(head3, temp1->val);
                head3 = insert(head3, temp2->val);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        // inserting the remaining values in the LL
        if(temp1){
            while(temp1 != NULL){
                head3 = insert(head3, temp1->val);
                temp1 = temp1->next;
            }
        }
        else{
            while(temp2 != NULL){
                head3 = insert(head3, temp2->val);
                temp2 = temp2->next;
            }           
        }
        return head3;
}

int main(){
    Node* head1 = NULL;
    head1 = insert(head1 ,1);
    head1 = insert(head1 ,2);
    head1 = insert(head1 ,4);

    Node* head2 = NULL;
    head2 = insert(head2 ,1);
    head2 = insert(head2 ,3);
    head2 = insert(head2 ,4);

    Node* head3 = NULL;

    head3 = merge(head1, head2);
    display(head3);


    return 0;
}