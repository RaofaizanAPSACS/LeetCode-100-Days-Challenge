/*
Problem link: 
https://leetcode.com/problems/wiggle-sort-ii/

Problem:
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.

 

*/
#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> &array, int size) {
  vector<int> output(size);
  vector<int> count;
  int max = array[0];

  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  for (int i = 0; i <= max; ++i) {
        count.push_back(0);
  }
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
  int k=0;
  for (int i = size-1; i >=0; i--) {
    array[k++] = output[i];
  }
}

void wiggleSort(vector<int>& nums) {
    countSort(nums,nums.size());
    vector<int> ans;
    for(int i=0,j=nums.size()/2;i<nums.size()/2 and j<nums.size();i++,j++){
        ans.push_back(nums[j]);
        ans.push_back(nums[i]);
    }
    if(nums.size()%2!=0){
        ans.push_back(nums[nums.size()-1]);
    }
    nums = ans;
}

int main(){ 
    vector<int> nums{1,5,1,1,6,4,1,2,3,5,8,0,1};
    wiggleSort(nums);
    for(auto x: nums)
        cout<<x<<" ";
    return 0;
}