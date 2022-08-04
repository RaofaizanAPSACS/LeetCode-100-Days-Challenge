/*
Problem link: 
https://leetcode.com/problems/implement-trie-prefix-tree/

Problem:
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and 
retrieve keys in a dataset of strings. There are various applications of this data structure, 
such as autocomplete and spellchecker.

Implement the Trie class:
--Trie() Initializes the trie object.
--void insert(String word) Inserts the string word into the trie.
--boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before),
 and false otherwise.
--boolean startsWith(String prefix) Returns true if there is a previously inserted string word 
that has the prefix prefix, and false otherwise.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    bool end;
    Node* hTable[26];
    Node(){
        end = false;
        for(int i=0;i<26;i++)
            hTable[i] = NULL;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insertWord(string &word,int i,Node* tmp){
        if(i >= word.size()){
            tmp->end = true;
            return;
        }
        if(tmp->hTable[word[i]-'a'] == NULL)
            tmp->hTable[word[i]-'a'] = new Node();
        tmp = tmp->hTable[word[i]-'a'];
        insertWord(word,i+1,tmp);
    }
    void insert(string word) {
        if(word.empty()) return;
        int i=0;
        insertWord(word,i,root);
    }
    bool searchWord(string &word,int i,Node* tmp){
        if(i >= word.size() and tmp->end){
            return true;
        }
        if(tmp->hTable[word[i]-'a'] != NULL)
            if(searchWord(word,i+1,tmp->hTable[word[i]-'a'])){
                return true;
            }
        return false;
    }
    bool search(string word) {
      if(word.empty()) return false;
      int i=0; 
      return searchWord(word,i,root);
    }
    bool searchPrefix(string &word,int i,Node* tmp){
        if(i >= word.size())
            return true;
        if(tmp->hTable[word[i]-'a'] != NULL)
            if(searchPrefix(word,i+1,tmp->hTable[word[i]-'a'])){
                return true;
            }
        return false;        
    }
    bool startsWith(string prefix) {
        if(prefix.empty()) return false;
        int i=0;
        return searchPrefix(prefix,i,root);
    }
};
int main(){ 
    Trie* obj = new Trie();
    obj->insert("word"); 
    cout<<obj->startsWith("fai");
    return 0;
}