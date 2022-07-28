/*
Problem link: 
https://leetcode.com/problems/contains-duplicate-ii/

Problem:
Given an integer array nums and an integer k, 
return true if there are two distinct indices i and j in the array such that 
nums[i] == nums[j] and abs(i - j) <= k.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool comparator( pair<int,int>& a, pair<int,int>& b){
    return a.first < b.first;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    vector<pair<int,int> > sortedValues;
    for(int i=0;i<nums.size();i++)
        sortedValues.push_back(pair(nums[i],i));
    sort(sortedValues.begin(),sortedValues.end(),comparator);
    
    for(int i=1;i<sortedValues.size();i++){
        if(sortedValues[i-1].first == sortedValues[i].first)
            if(abs(sortedValues[i-1].second - sortedValues[i].second) <= k)
                return true;
    } 

    return false;
}

int main(){
    vector<int> nums {1,2,3,1,2,3};
    cout<<containsNearbyDuplicate(nums,2);
    return 0;
    
}