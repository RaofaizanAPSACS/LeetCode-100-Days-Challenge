/*
Problem link: 
https://leetcode.com/problems/reshape-the-matrix/

Problem:
You are given an m x n matrix mat and two integers r and c representing the number of rows and 
the number of columns of the wanted reshaped matrix.

 
Algorithm or Approach :  

*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    vector<int> temp;
    int k=0;
    if((mat.size()*mat[0].size()) == r*c){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                temp.push_back(mat[i][j]);
                // cout<<mat[i][j];
            }
        }
        mat.clear();
        for(int i=0;i<r;i++){
            vector<int> tmp;
            for(int j=0;j<c;j++){
                tmp.push_back(temp[k++]);
            }
            mat.push_back(tmp);
        }
    }
    return mat;
}

int main(){ 
    vector<vector<int>> res,mat{
        {1,2},
        {4,5},
        {7,8}
    };
    res = matrixReshape(mat,3,3);
    for(auto x: res){
        for(auto y: x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}