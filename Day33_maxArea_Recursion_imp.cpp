/*
Problem link: 
https://leetcode.com/problems/max-area-of-island/

Problem:
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

*/
#include <bits/stdc++.h>
using namespace std;

void countArea(vector<vector<int>> &grid, int &count, int i, int j){
    if(grid[i][j] == 0)
        return;

    grid[i][j] = 0;
    count++;

    if(j-1 >= 0 ){
        countArea(grid, count, i, j-1);
    }
    if(j+1 < grid[0].size()){
        countArea(grid, count, i, j+1);
    }
    if(i-1 >= 0){
        countArea(grid, count, i-1, j);
    }
    if(i+1 < grid.size()){
        countArea(grid, count, i+1, j);
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int temp=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] == 1){
                int count = 0;
                countArea(grid, count, i, j);
                temp = max(count,temp);
            }
        }
    }
    return temp;
}

int main(){
    vector<vector<int>> grid{
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    // vector<vector<int>> grid{
    //     {1,1,0,0,0},
    //     {1,1,0,0,0},
    //     {0,0,0,1,1},
    //     {0,0,0,1,1}
    // };
    cout<<maxAreaOfIsland(grid);
    return 0;
}