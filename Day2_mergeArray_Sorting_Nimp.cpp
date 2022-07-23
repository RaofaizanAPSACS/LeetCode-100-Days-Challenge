/*
Problem link: 
https://leetcode.com/problems/merge-sorted-array/submissions/

Problem:
Given the two sorted arrays, the task is to merge the two arrays such that the elements 
should be in sorted order after the merge.

Algorithm :  Two Fingers approach

*/
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> temp = nums1; // using extra O(m) storage to store the num1 array 
    nums1.clear();
    int i=0,j=0;
    while(i<m and j<n){
        if(temp[i] < nums2[j]){
            nums1.push_back(temp[i]);
            i++;
        }
        else if(nums2[j] < temp[i]){
            nums1.push_back(nums2[j]);
            j++;
        }
        else{
            nums1.push_back(temp[i]);
            nums1.push_back(nums2[j]);
            i++;
            j++;
        }
    }
    if(i == m){
        while(j<n){
            nums1.push_back(nums2[j]); j++;
        }
    }
    else if(j == n){
        while(i<m){
            nums1.push_back(temp[i]); i++;
        }
    }
}

int main(){
    vector<int> n1,n2;
    n1.push_back(1);
    // n1.push_back(2);
    // n1.push_back(3);
    // n1.push_back(0);
    // n1.push_back(0);
    // n1.push_back(0);

    // n2.push_back(2);
    // n2.push_back(5);
    // n2.push_back(6);

    merge(n1,1,n2,n2.size());
    for(int i=0;i<n1.size();i++){
        cout<<n1[i]<<" ";
    }

    return 0;
}