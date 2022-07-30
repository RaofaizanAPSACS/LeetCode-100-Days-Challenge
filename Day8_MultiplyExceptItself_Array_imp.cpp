/*
Problem link: 
https://leetcode.com/problems/product-of-array-except-self/

Problem:
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Algorithm or Approach :  multiply prefix and suffix arrays

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res,prefix(nums.size()),suffix(nums.size(),0);
    prefix[0] = suffix[nums.size()-1] =  1;

    for(int i=1;i<nums.size();i++){
        prefix[i] = prefix[i-1]*nums[i-1];
    }
    for(int i=nums.size()-2;i>=0;i--){
        suffix[i] = suffix[i+1]*nums[i+1];
    }
    for(int i=0;i<nums.size();i++){
        res.push_back(prefix[i]*suffix[i]);
    }
    return res;
}

int main(){
    vector<int> arr{1,2,3,4};
    vector<int> nums = productExceptSelf(arr);
    for(auto x: nums)
        cout<<x<<" ";
    return 0;
    
}