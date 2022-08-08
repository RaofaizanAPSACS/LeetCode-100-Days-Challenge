/*
Problem link: 
https://leetcode.com/problems/subsets/

Problem:
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

 
Algorithm or Approach :  

*/
#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> res;
void solve(vector<int> &subsets,vector<int> &nums,int j){
    if(j == nums.size()-1){
        res.push_back(subsets);
        return;
    }
    subsets.push_back(nums[j]);
    solve(subsets,nums,j+1);
    res.push_back({nums[j]});
    // subsets.push_back(nums[j]);
    solve(subsets,nums,j+1);
    subsets.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> subsets;
    solve(subsets,nums,0);
    return res;
}

int main(){ 
    vector<int> nums{3,2,4,1};
    vector<vector<int>> res = subsets(nums);
    cout<<res.size()<<endl;
    for(auto x: res){
        for(auto y: x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}