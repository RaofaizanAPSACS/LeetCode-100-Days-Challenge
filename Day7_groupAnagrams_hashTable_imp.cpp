/*
Problem link: 
https://leetcode.com/problems/group-anagrams/

Problem:
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<string>> &matrix){
    for(auto x: matrix){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
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
vector<vector<string>> groupAnagrams(vector<string> &str){
    vector<vector<string>> res(str.size());
    int k=0;
    for(int i=0;i<str.size();i++){
        res[k].push_back(str[0]);
        for(int j=i+1;j<str.size();j++){
            if(str.empty()) break;
            if(isAnagram(str[i],str[j])){
                res[k].push_back(str[j]);
                str.erase(str.begin()+j);
                j--;
            }
        }
        str.erase(str.begin());
        if(str.empty()) break;
        i--; k++;
    }
    k=0; 
    int size = res.size();
    for(int i=0;i<res.size();i++)
        if(res[i].size() == 0){
            k = i; break;
        } 
    if(k)
        for(int i=k;i<size;i++){
            res.erase(res.begin()+k);
        }    
           
    return res;
}

int main(){
    vector<string> str{"","b"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(str);
    display(groupedAnagrams);
    cout<<groupedAnagrams.size();
    return 0;
    
}