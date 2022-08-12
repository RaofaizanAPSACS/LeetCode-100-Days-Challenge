/*
Problem link: 
https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/

Problem:
You have a 1-indexed binary string of length n where all the bits are 0 initially. 
We will flip all the bits of this binary string (i.e., change them from 0 to 1) one by one. 
You are given a 1-indexed integer array flips where flips[i] indicates that 
the bit at index i will be flipped in the ith step.

A binary string is prefix-aligned if, after the ith step, all the bits in the inclusive 
range [1, i] are ones and all the other bits are zeros.

Return the number of times the binary string is prefix-aligned during the flipping process.

 

*/
#include<bits/stdc++.h>
using namespace std;

int numTimesAllBlue(vector<int>& flips) {
    int prefixCount=0,m=INT_MIN;
    for(int i=0;i<flips.size();i++){
        m = max(m,flips[i]);
        if(m == i+1)
            prefixCount++;
    }
    return prefixCount;
}

int main(){ 
    vector<int> flips{4,1,2,3};
    cout<<numTimesAllBlue(flips);
    return 0;
}