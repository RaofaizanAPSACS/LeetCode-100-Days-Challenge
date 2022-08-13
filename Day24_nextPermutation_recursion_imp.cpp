/*
Problem link: 
https://leetcode.com/problems/next-permutation/

Problem:
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/
#include<bits/stdc++.h>
using namespace std;

void permutations(string nums,string ans, vector<string> &allper){
    if(nums.size() == 0){
        allper.push_back(ans);
        return;
    }
    for(int i=0;i<nums.size();i++){
        char ch = nums[i];
        string left = nums.substr(0,i);
        string right = nums.substr(i+1);
        permutations(left + right, ans+ch, allper);
    }
}
void nextPermutation(vector<int> &nums){
    vector<int> arr(nums);
    vector<string> ans;
    string s1="",s2="", temp="";
    int index=-1;


    sort(arr.begin(),arr.end());
    for(int i=0;i<nums.size();i++)
        s1 += to_string(nums[i]);
    for(int i=0;i<nums.size();i++)
        s2 += to_string(arr[i]);

    permutations(s2,temp,ans);

    if(s1 == ans[ans.size()-1]){
        nums = arr; return;
    }

    for(int i=ans.size()-1;i>=0;i--){
        if(i+1 < ans.size() and ans[i] == s1){
            index = i+1;
            break;
        }
    }
    for(int i=0;i<nums.size();i++){
        string temp = "";
        temp += ans[index][i];
        nums[i] = stoi(temp);
    }
    for(auto x: ans)
        cout<<x<<endl;
}

int main(){   
    vector<int> nums{1,5,1};
    nextPermutation(nums);
    for(auto x: nums)
        cout<<x<<" ";
	return 0;
}