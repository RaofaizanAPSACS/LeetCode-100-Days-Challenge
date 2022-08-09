/*
Problem link: 
https://leetcode.com/problems/rearrange-array-elements-by-sign/

Problem:
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and 
negative integers.
You should rearrange the elements of nums such that the modified array follows the given conditions:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Algorithm or Approach :  --

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int size = nums.size();
    vector<int> ans;
    for(int i=0;i<size;i++){
        if(nums[i] > 0)
            nums.push_back(nums[i]);
    }
    for(int i=0;i<size;i++){
        if(nums[i] < 0)
            nums.push_back(nums[i]);
    }
    for(int i=size,j=int(size*1.5);i<int(size*1.5) and j<2*size;i++,j++){
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
    }
    return ans;
}

int main(){ 
    vector<int> res,nums{3,1,-2,-5,2,-4};
    res = rearrangeArray(nums);
    for(auto x: nums)   
        cout<<x<<" ";
    return 0;
}