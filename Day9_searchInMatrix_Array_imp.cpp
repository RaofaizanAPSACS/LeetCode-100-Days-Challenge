/*
Problem link: 
https://leetcode.com/problems/search-a-2d-matrix-ii/

Problem:
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// bool searchMatrix(vector<vector<int>>& matrix, int target,int row, int col) {
//     if(col < matrix[0].size()){
//         for(int i=col;i<matrix[0].size();i++){
//             if(matrix[row][i] == target)
//                 return true;
//             if(target < matrix[row][i])
//                 break;
//         }
//     }
//     if(row < matrix.size()){
//         if(row+1 >= matrix.size()) return false;
//         for(int i=row+1;i<matrix.size();i++){
//             if(matrix[i][col] == target)
//                 return true;
//             if(target < matrix[i][col])
//                 break;
//         } 
//     }
//     if(searchMatrix(matrix,target,row+1,col+1)) 
//         return true;

//     return false;
// }
bool BinarySearch(vector<int> &arr,int l, int h, int target){
    if(l <= h){
        int mid = (l+h)/2;
        if(arr[mid] == target)
            return true;
        if(target < arr[mid])
            return BinarySearch(arr,l,mid-1,target);
        else    
            return BinarySearch(arr,mid+1,h,target);
    }
    return  false;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i=0;i<matrix.size();i++)
        if(BinarySearch(matrix[i],0,matrix[i].size()-1,target))
            return true;
    return false;
}

int main(){ 
    vector<vector<int>> matrix{
        {3,7},
        {5,8},
        {9,11},
        {9,15}
    };
    cout<<searchMatrix(matrix,12);
    return 0;
    
}