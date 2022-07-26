/*
Problem link: 
https://leetcode.com/problems/spiral-matrix/

Problem:
Given an m x n matrix, return all elements of the matrix in spiral order.

Algorithm or Approach :  Deleting the first row, last column, last row and first column of matrix
                        until its size reaches to zero.

*/
#include<bits/stdc++.h>
using namespace std;

// Handling row and column operations for spiral movement individualy
void firstRow(vector<vector<int>> &matrix,vector<int> &ans){
    // insert the first row
    for(int i=0;i<matrix[0].size();i++)
        ans.push_back(matrix[0][i]);    
    // delete the first row
    matrix.erase(matrix.begin());
}

void lastColumn(vector<vector<int>> &matrix,vector<int> &ans){
    //insert the last column
    for(int i=0;i<matrix.size();i++)
        ans.push_back(matrix[i][ matrix[i].size()-1]);
    // delete the last column
    if(matrix[0].size() == 1)
        matrix.clear();
    else
        for(int i=0;i<matrix.size();i++)
            matrix[i].pop_back();
}
void lastRow(vector<vector<int>> &matrix,vector<int> &ans){
    // insert the last row
    for(int i=matrix[0].size()-1;i>=0;i--)
        ans.push_back(matrix[matrix.size()-1][i]);    
    // delete the last row
    matrix.erase(matrix.end());
}
void firstColumn(vector<vector<int>> &matrix,vector<int> &ans){
    // insert the first column
    for(int i=matrix.size()-1;i>=0;i--)
        ans.push_back(matrix[i][0]);
        
    // delete the first column
    if(matrix[0].size() == 1)
        matrix.clear();
    else
        for(int i=0;i<matrix.size();i++)
            matrix[i].erase(matrix[i].begin());
}


vector<int> spiralOrder(vector<vector<int>> matrix) {
    vector<int> ans;
    while(!matrix.empty()){
        if(!matrix.empty())
            firstRow(matrix,ans);
        if(!matrix.empty())
            lastColumn(matrix,ans);
        if(!matrix.empty())
            lastRow(matrix,ans);
        if(!matrix.empty())
            firstColumn(matrix,ans);
    }
    return ans;
}


int main(){
    vector<vector<int>> matrix
    {
        {1, 2, 3 , 4 , 3, 3, 3},
        {1, 2, 3 , 4 , 3, 3, 3},
        {1, 2, 3 , 4 , 3, 3, 3},
        {1, 2, 3 , 4 , 3, 3, 3},
        {1, 2, 3 , 4 , 3, 3, 3},
        {1, 2, 3 , 4 , 3, 3, 3},
        {1, 2, 3 , 4 , 3, 3, 3}
    };
    vector<int> nums;
    nums = spiralOrder(matrix);
    for(auto x: nums)
        cout<<x<<" ";
    return 0;
}