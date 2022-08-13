/*
Problem link: 
https://leetcode.com/problems/shuffle-an-array/

Problem:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] 
and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
*/
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int l,int h, int target){
    if(l<=h){
        int mid = (l+h)/2;
        if(nums[mid] == target)
            return mid;
        if(target < nums[mid])
            return binarySearch(nums,l,mid-1,target);
        else   
            return binarySearch(nums,mid+1,h,target);
    }
    return -1;
}

// alternative solution using MAP 
vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int,vector<int> > m;
    for(int i=0;i<nums.size();i++)
        m[nums[i]].push_back(i);
    for(int i=0;i<nums.size();i++){
        int temp=-1;
        if(m.find(target-nums[i]) != m.end()){
                temp = m[target-nums[i]][0];
            if(nums[i] !=0 and target-nums[i] == target or target-nums[i] == nums[i])
                temp = m[target-nums[i]][1];
        }
        if(temp != -1){
            res.push_back(i+1);
            res.push_back(temp+1);
            break;
        }
    }
    return res;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for(int i=0;i<nums.size();i++){
        int temp = binarySearch(nums,i+1,nums.size()-1,target-nums[i]);
        if(temp != -1){
            res.push_back(i+1);
            res.push_back(temp+1);
            break;
        }
    }
    return res;
}
int main(){   
    vector<int> res,nums{2,3,4};
    res = twoSum(nums,5);
    for(auto x: res)
        cout<<x<<" ";
	return 0;
}