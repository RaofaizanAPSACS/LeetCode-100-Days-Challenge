/*
Problem link: 
https://leetcode.com/problems/make-sum-divisible-by-p/

Problem:
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that 
the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
A subarray is defined as a contiguous block of elements in the array.

*/
#include<bits/stdc++.h>
using namespace std;

int checkOneElement(long sum,vector<int> &nums,int p){
    for(int i=0;i<nums.size();i++){
        if((sum-nums[i])%p == 0)
            return 1;
    }
    return 0;
}

int minSubarray(vector<int> &nums,int p){
    long sum=0;
    int count=INT_MAX;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];
    if(sum < p)
        return -1;
    if(sum%p == 0)
        return 0;
    if(checkOneElement(sum,nums,p))
        return 1;
    long Presum=0;
    for(int i=0;i<nums.size();i++){
        Presum+=nums[i];
        for(int j=i+1;j<nums.size();j++){
            Presum+=nums[j];
            if(sum-Presum !=0 and (sum-Presum)%p == 0){
                if(j+1-i < count)
                    count = j+1-i;
                break;
            }
        }
        Presum = 0;
    }
    if(count == INT_MAX)
        return -1;
    else return count;
}

int main(){ 
    vector<int> nums{19,25,39,31,20,10,40,38,28,35,11,11,18,26,26,24,29,14,10,37};
    cout<<minSubarray(nums,23);
    return 0;
}