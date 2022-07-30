/*
Problem link: 
https://leetcode.com/problems/search-insert-position/

Problem:
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Algorithm or Approach :  Binary Search

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr,int l, int h, int target){
    if(l <= h){
        int mid = (l+h)/2;
        if(arr[mid] == target)
            return mid;
        if(target < arr[mid])
            return BinarySearch(arr,l,mid-1,target);
        else    
            return BinarySearch(arr,mid+1,h,target);
    }
    return l;
}

int main(){ 
    vector<int> arr{1,2,3,4,5,6,7,9,10};
    cout<<BinarySearch(arr,0,arr.size()-1,20);
    return 0;
    
}