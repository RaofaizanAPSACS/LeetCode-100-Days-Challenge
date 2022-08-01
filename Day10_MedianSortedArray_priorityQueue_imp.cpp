/*
Problem link: 
https://leetcode.com/problems/median-of-two-sorted-arrays/

Problem:
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Algorithm or Approach :  priority queue

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    priority_queue <int, vector<int>, greater<int>> nums;

    for(int i=0;i<nums1.size();i++)
        nums.push(nums1[i]);
    for(int i=0;i<nums2.size();i++)
        nums.push(nums2[i]);

    double median=0,index = (nums.size()-1)/2;
    
    while(!nums.empty()){
        if(index == 0){
            median = nums.top();
        }
        if((nums.size()%2 == 0) and index == -1){
            median += nums.top();
            median /= 2;
        }
        nums.pop();
        index--;
    }
    return median;
}
int main(){ 
    vector<int> n1{2},n2{0,1};
    cout<<findMedianSortedArrays(n1,n2);
    return 0;
    
}