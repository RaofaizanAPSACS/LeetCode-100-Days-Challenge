/*
Problem link: 
https://leetcode.com/problems/single-number-iii/

Problem:
Given an integer array nums, in which exactly two elements appear only once and all the other 
elements appear exactly twice. Find the two elements that appear only once. You can return the
 answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> singleNumber(vector<int>& nums){
    vector<int> res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i+1 < nums.size()){
            if(nums[i] != nums[i+1])
                res.push_back(nums[i]);
            else
                i++;
        }
        else
            res.push_back(nums[i]);
    }
    return res;
}
int main(){   
    vector<int> res, nums{1,1,2,2,3,5};
    res = singleNumber(nums);
    for(auto x: res)
        cout<<x<<" ";
	return 0;
}