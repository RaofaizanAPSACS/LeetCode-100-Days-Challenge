/*
Problem link: 
https://leetcode.com/problems/daily-temperatures/

Problem:
Given an array of integers temperatures represents the daily temperatures, return an array answer such 
that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    bool flag = false;
    for(int i=0;i<temperatures.size()-1;i++){
        for(int j=i+1;j<temperatures.size();j++){
            if(temperatures[j] > temperatures[i]){
                temperatures[i] = j-i;
                flag = true;
                break;
            }
        }
        if(!flag)
            temperatures[i] = 0;
        flag = false;
        
    }
    temperatures[temperatures.size()-1] = 0;
    return temperatures;
}

int main(){   
    vector<int> res,nums{73,74,75,71,69,72,76,73};
    res = dailyTemperatures(nums);
    for(auto x: res)
        cout<<x<<" ";
	return 0;
}