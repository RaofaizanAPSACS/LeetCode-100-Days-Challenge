/*
Problem link: 
https://leetcode.com/problems/next-permutation/

Problem:
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/
#include<bits/stdc++.h>
using namespace std;

// SOLUTION 1 : BRUTE FORCE APPROACH
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


// SOLUTION 2: GREEDY APPROACH
void nextPermutation2(vector<int> &nums){
    int i;
    for(i=nums.size()-1;i>=1;i--){
        if(nums[i] > nums[i-1])
            break;
    }
    if(i == 0)
        reverse(nums.begin(),nums.end());
    else{
        for(int j=nums.size()-1; j>=i; j--){
            if(nums[j] > nums[i-1])
                swap(nums[j],nums[i-1]);
                break;
        }
        reverse(nums.begin()+i, nums.end());
    }
}

int main(){   
    vector<int> nums{1,2,3};
    nextPermutation2(nums);
    for(auto x: nums)
        cout<<x<<" ";
	return 0;
}