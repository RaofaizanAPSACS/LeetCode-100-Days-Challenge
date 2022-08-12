/*
Problem link: 
https://leetcode.com/problems/shift-2d-grid/

Problem:
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.

 

*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size()));
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            int c = j+k, r=i+c/grid[0].size();
            r%=grid.size();
            c%=grid[0].size();
            ans[r][c] = grid[i][j];
        }
    }
    return ans;
}

int main(){ 
    vector<vector<int>> res,mat{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    res = shiftGrid(mat,2);
    for(auto x: res){
        for(auto y: x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}