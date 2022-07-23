/*
Problem link: 
https://leetcode.com/problems/climbing-stairs/

Problem:
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Algorithm or Approach :  fibonacci series 

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;


// recursive solution 
int climbStairs1(int n){
    if(n <= 2)
        return n;
    else 
        return climbStairs1(n-1) + climbStairs1(n-2);
}

// iterative solution
int climbStairs2(int n){
    if(n <= 2)
        return n;
    else{
        int arr[n+1];
        arr[1] = 1;
        arr[2] = 2;
        for(int i=3;i<=n;i++){
            arr[i] = arr[i-2] + arr[i-1];
        }
        return arr[n];
    }
}

int main(){
    cout<<climbStairs1(3);
}