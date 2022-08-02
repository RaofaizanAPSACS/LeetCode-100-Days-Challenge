/*
Problem link: 
https://leetcode.com/problems/rotate-image/

Problem:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    vector<vector<int>> mat(matrix.size());
    int i=matrix[0].size()-1,j=0;
    while(i>=0){
      while(j < matrix.size()){
            mat[j].push_back(matrix[i][j]);  
            j++;   
      }
      i--;
      j=0;
    }
    matrix = mat;
}
int main(){ 
    vector<vector<int>> matrix{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}