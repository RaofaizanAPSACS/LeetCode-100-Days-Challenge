/*
Problem link: 
https://leetcode.com/problems/valid-anagram/

Problem:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Algorithm or Approach :  sorting both the strings using sorted MAP(hashtable) and counting their occurences.

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// comparing the two instances of the Maps whether they are same or not
bool compare(map<char, int> &m1, map<char, int> &m2){
    return m1.size() == m2.size() && std::equal(m1.begin(), m1.end(), m2.begin());
}

bool isAnagram(string s, string t){
    map<char, int> m1,m2;
    for(int i=0;i<s.size();i++)
        m1[s[i]]++;
    for(int j=0;j<t.size();j++)
        m2[t[j]]++;

    return compare(m1, m2);
}

int main(){
    cout<<isAnagram("anagram","nagaram");
    return 0;
    
}