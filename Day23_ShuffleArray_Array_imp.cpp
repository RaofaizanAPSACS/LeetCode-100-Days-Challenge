/*
Problem link: 
https://leetcode.com/problems/shuffle-an-array/

Problem:
Given an integer array nums, design an algorithm to randomly shuffle the array. 
All permutations of the array should be equally likely as a result of the shuffling.

 

*/
#include<bits/stdc++.h>
using namespace std;

std::random_device rd;
std::mt19937 gen(rd());
int random(int low, int high)
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}


class Solution {
    vector<int> originalArray;
public:
    Solution(vector<int>& nums) {
        originalArray = nums;
    }
    
    vector<int> reset() {
        return originalArray;
    }
    
    vector<int> shuffle() {
        vector<int> shuffeledArray, m(originalArray.size());
        shuffeledArray.clear();
        for(int i=0;i<originalArray.size();i++){
            int n = random(0,originalArray.size()-1);
            m[n]++;
            shuffeledArray.push_back(originalArray[n]);
            while(m[n] > 1){
                shuffeledArray.pop_back();
                m[n]--;
                n = random(0,originalArray.size()-1);
                m[n]++;
                shuffeledArray.push_back(originalArray[n]);
            }
        }
        return shuffeledArray;
    }
};
int main()
{
    vector<int> res,nums{-6,10,184};
    Solution *obj = new Solution(nums);
    res = obj->shuffle();
    for(auto x: res)
        cout<<x<<" ";

	return 0;
}