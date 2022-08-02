/*
Problem link: 
https://leetcode.com/problems/word-pattern/

Problem:
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern 
and a non-empty word in s.

Algorithm or Approach :  Store the indices of same values in string pattern in MAP and then use those indices

to check whether the values on each of those indexes of words vector are same or not.

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char,vector<int> > patternMap;
    set<string> uniqueStrings,uniqueLetters;
    istringstream ss(s);
    string word;
    vector<string> words;
    while(ss>>word){
        words.push_back(word);
        uniqueStrings.insert(word);
    }
    for(int i=0;i<pattern.size();i++){
        patternMap[pattern[i]].push_back(i);
        string temp = "";
        temp += pattern[i];
        uniqueLetters.insert(temp);
    }
    if(uniqueLetters.size() != uniqueStrings.size())
        return false;

    if(pattern.size() != words.size())
        return false;

    for(auto x: patternMap){
        vector<int> v = x.second;
        for(int i=1;i<v.size();i++){
            if(words[v[i]] != words[v[0]])
                return false;
        }  
    }
    return true;
}

int main(){ 
    cout<<wordPattern("aba","cat cat cat dog");
    return 0;
    
}