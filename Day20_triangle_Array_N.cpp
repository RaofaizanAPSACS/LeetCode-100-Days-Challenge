/*
Problem link: 
https://leetcode.com/problems/triangle/

Problem:
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

*/
#include<bits/stdc++.h>
using namespace std;

void find(vector<vector<int>> &tri,int i,int j,int sum,int &m,map<pair<int,int>,int> &dp){
    if(i >= tri.size()){
        m = min(m,sum);
        return;
    }
    dp[pair(i,j)] = tri[i][j];
    sum+=tri[i][j];
    find(tri,i+1,j,sum,m,dp);
    find(tri,i+1,j+1,sum,m,dp);
    
}
int minimumTotal(vector<vector<int>>& triangle) {
    int min=INT_MAX;
    if(triangle.size() == 1)
        return triangle[0][0];
    map<pair<int,int>,int> dp;
    find(triangle,0,0,0,min,dp);
    return min;
}
int main(){ 
    vector<vector<int>> tri{
        {-1},
        {2,3},
        {1,-1,-3},
    };
    cout<<minimumTotal(tri);
    return 0;
}