/*
Problem link: 
https://leetcode.com/problems/search-in-rotated-sorted-array/

Problem:
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index 
k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], 
nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and 
become [4,5,6,7,0,1,2].
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
int findPivot(vector<int> &nums, int l,int h){
    if(l == h-1){
        return h;
    }
    int mid = (l+h)/2;
    if(nums[l] > nums[mid])
        return findPivot(nums,l,mid);
    else if(nums[h] < nums[mid])   
        return findPivot(nums,mid,h);
    else
        return -1;
}
int search(vector<int>& nums, int target) {
    int pivot = findPivot(nums,0,nums.size()-1);
    if(pivot != -1)
        return max(binarySearch(nums,0,pivot-1,target),binarySearch(nums,pivot,nums.size()-1,target));
    else
        return binarySearch(nums,0,nums.size()-1,target);
}
int main(){   
    vector<int> nums{4,5,6,7,0,1,2,3};
    cout<<search(nums,0);
	return 0;
}