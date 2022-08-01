/*
Problem link: 
https://leetcode.com/problems/plus-one/

Problem:
You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& ans) {
    int index = ans.size()-1;
    while(index>=0 and ans[index] == 9){
        ans[index] = 0;
        index--;
    }
    if(index < 0){ 
        ans.insert(ans.begin(),0);
        index++;
    }

    ans[index] += 1;
    return ans;
}
int main(){ 
    vector<int> nums{1, 1, 9};
    vector<int> ans = plusOne(nums);
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
    
}