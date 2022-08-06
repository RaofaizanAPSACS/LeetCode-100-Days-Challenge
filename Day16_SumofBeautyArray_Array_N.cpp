/*
Problem link: 
https://leetcode.com/problems/sum-of-beauty-in-the-array/

Problem:
You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:

2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
0, if none of the previous conditions holds.
Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.

 
Algorithm or Approach :  
-Used max of the prefix and min of the suffix -
- MinMaxQueue to get min in O(1) time.

*/
#include<bits/stdc++.h>
using namespace std;


class MinMaxQueue {
public:
    queue<int> Q;
    deque<int> D;
    void enque_element(int element)
    {
        if (Q.size() == 0) {
            Q.push(element);
            D.push_back(element);
        }
        else {
            Q.push(element);
            while (!D.empty() &&
               D.back() > element) {
                D.pop_back();
            }
            D.push_back(element);
        }
    }
    void deque_element()
    {
        if (Q.front() == D.front()) {
            Q.pop();
            D.pop_front();
        }
        else {
            Q.pop();
        }
    }
    int size(){
        return Q.size();
    }
    int getMin()
    {
        return D.front();
    }
};
int sumOfBeauties(vector<int>& nums){
    int sum=0,max=nums[0];
    bool two=false;
    MinMaxQueue q;
    for(auto x: nums)
        q.enque_element(x);
    q.deque_element();
    q.deque_element();

    for(int i=1;i<=nums.size()-2;i++){
        if(nums[i-1] > max)
            max = nums[i-1];
        if(max < nums[i] and nums[i] < q.getMin()){
            sum += 2;
            two = true;
        }
        if(!two){
            if(nums[i-1] < nums[i] and nums[i] < nums[i+1])
                sum += 1;
        }
        two = false;
        q.deque_element();
    }
    return sum;
}


int main(){ 
    vector<int> v{6,1,10,17,19,17,20};
    cout<<sumOfBeauties(v);
    return 0;
}