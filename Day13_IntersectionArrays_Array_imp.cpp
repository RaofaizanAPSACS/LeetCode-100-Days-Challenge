/*
Problem link: 
https://leetcode.com/problems/intersection-of-two-arrays-ii/

Problem:
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and 
you may return the result in any order.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    unordered_map<int,int> m1;
    for(auto x: nums1)
        m1[x]++;
    for(int i=0;i<nums2.size();i++){
        if(m1[nums2[i]]){
            res.push_back(nums2[i]);
            m1[nums2[i]]--;
        }
    }
    return res;
}
int main(){ 
    vector<int> res,nums1{1,2,2,1},nums2{2,2};
    res = intersect(nums1,nums2);
    for(auto x: res)
        cout<<x<<" ";
    return 0;
    
}