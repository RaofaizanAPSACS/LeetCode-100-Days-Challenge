/*
Problem link: 
https://leetcode.com/problems/set-matrix-zeroes/

Problem:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows,cols;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for(auto x: rows){
        for(int i=0;i<matrix[0].size();i++){
            matrix[x][i] = 0;
        }
    }
    for(auto x: cols){
        for(int i=0;i<matrix.size();i++){
            matrix[i][x] = 0;
        }
    }
}

int main(){ 
    vector<vector<int>> matrix{
        {0,1,2,0},
        {3,4,5,6},
        {7,8,9,2}
    };
    setZeroes(matrix);

    for(auto x: matrix){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}