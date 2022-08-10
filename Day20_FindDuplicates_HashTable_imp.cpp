/*
Problem link: 
https://leetcode.com/problems/find-all-duplicates-in-an-array/

Problem:
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and 
each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

 
Algorithm or Approach :  Used Map to record the frequencies of the values in array and if any freq is 
greater than 1, count that value as the duplicate of the array.

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums){
    map<int,int> freq;
    vector<int> res;
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
    }
    for(auto x: freq){
        if(x.second > 1){
            res.push_back(x.first);
        }
    }
    return res;
}

int main(){ 
    vector<int> res,nums{4,3,2,7,8,2,3,1};
    res = findDuplicates(nums);
    for(auto x: res)
        cout<<x<<" ";
    return 0;
}