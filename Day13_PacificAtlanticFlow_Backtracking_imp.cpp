/*
Problem link: 
https://leetcode.com/problems/pacific-atlantic-water-flow/

Problem:
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, 
and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells.
 You are given an m x n integer matrix heights where heights[r][c] represents 
 the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, 
south, east, and west if the neighboring cell's height is less than or equal to the current cell's height.
 Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] 
denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Algorithm or Approach :  Recursion & Backtracking

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// bool isSafe(vector<vector<int>> &h,vector<vector<bool>> &visited,int i, int j,long cur){
//     if(i < 0 or j < 0 or i >= h.size() or j >= h[0].size() or visited[i][j] or cur < h[i][j])
//         return false;
//     return true;
// }
void find(vector<vector<int>> &heights, pair<bool,bool> &mark, int i, int j, vector<vector<bool>> &visited,long cur){
    if(i < 0 or j < 0){
        mark.first = true; return;
    }
    if(i >= heights.size() or j >= heights[0].size()){
        mark.second = true; return;
    }
    if(!(i < 0 or j < 0 or i >= heights.size() or j >= heights[0].size() or visited[i][j] or cur < heights[i][j])){
        visited[i][j] = true;

            find(heights,mark,i,j+1,visited,heights[i][j]);
            find(heights,mark,i+1,j,visited,heights[i][j]);
            find(heights,mark,i,j-1,visited,heights[i][j]);
            find(heights,mark,i-1,j,visited,heights[i][j]);

        visited[i][j] = false;
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans;
    vector<vector<bool>> visited(heights.size(),vector<bool> (heights[0].size(),false));
    pair<bool,bool> mark{false,false};
    for(int i=0;i<heights.size();i++){
        for(int j=0;j<heights[0].size();j++){
            find(heights,mark, i,j,visited,LONG_MAX);   
            if(mark.first and mark.second){
                ans.push_back({i,j});
            }
            mark = {false, false};
        }
    }
    return ans;
}

int main(){ 
    vector<vector<int>> h{
       {1,2,2,3,5},
       {3,2,3,4,4},
       {2,4,5,3,1},
       {6,7,1,4,5},
       {5,1,1,2,4}
    }, ans;
    ans = pacificAtlantic(h);
    for(auto x: ans){
        for(auto y: x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}