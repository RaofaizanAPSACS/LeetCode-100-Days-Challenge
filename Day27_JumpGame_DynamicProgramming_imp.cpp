/*
Problem link: 
https://leetcode.com/problems/jump-game/

Problem:
You are given an integer array nums. You are initially positioned at the array's first index, and 
each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/
#include<bits/stdc++.h>
using namespace std;

// with dynamic programming
bool recur(vector<int>& nums, int i,vector<int> &dp){
    if(i >= nums.size()-1)  
        return true;
    if(dp[i] != INT_MAX) 
        return dp[i];
    for(int k=nums[i];k>=1;k--){
        if(i+k >= nums.size()-1) 
            return true;
        if(recur(nums,i+k,dp)){
            dp[i+k] = 1;
            return true;
        }
        else    
            dp[i+k] = 0;
    }
    return false;
}
// without dynamic programming
bool recur2(vector<int>& nums, int i){
    if(i >= nums.size()-1)  
        return true;
    for(int k=nums[i];k>=1;k--)
        if(recur2(nums,i+k))
            return true;

    return false;
}
bool canJump(vector<int>& nums) {
    vector<int> dp(nums.size()+1,INT_MAX);
    return recur(nums,0,dp);
}

int main(){   
    vector<int> nums{2,3,1,1,4};
    cout<<canJump(nums);
	return 0;
}