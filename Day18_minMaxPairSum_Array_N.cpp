/*
Problem link: 


Problem:


 
Algorithm or Approach :  

*/
#include<bits/stdc++.h>
using namespace std;


int minPairSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int max = nums[0] + nums[nums.size()-1];
    for(int i=0,j=nums.size()-1;i<nums.size()/2 and j >= nums.size()/2;i++,j--){
        if(nums[i] + nums[j] > max)
            max = nums[i] + nums[j];
    }
    return max;
}

int main(){ 
    vector<int> nums{3,5,4,2,4,6};
    cout<<minPairSum(nums);
    return 0;
}