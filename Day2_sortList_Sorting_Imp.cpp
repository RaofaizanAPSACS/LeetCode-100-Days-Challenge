/*
Problem link: 
https://leetcode.com/problems/sort-list/

Problem:
Given the head of a linked list, return the list after sorting it in ascending order.

Constraints:
Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

Algorithm :  Two Fingers approach

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


class SLL{
    Node* head;
    public:
        SLL(){
            head = NULL;
        }
        void insert(int d){
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
        }
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
        }
        void sortList(){
            
        }

};

int main(){
    SLL list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.display();
    
    return 0;
}