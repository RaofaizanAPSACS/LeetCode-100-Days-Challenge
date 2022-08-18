/*
Problem link: 
https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

Problem:
You are given an m x n binary matrix matrix.

You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

Return the maximum number of rows that have all values equal after some number of flips
*/
#include<bits/stdc++.h>
using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
     unordered_map<string,int> m;
     for(int i=0;i<matrix.size();i++){
        string s="",sf="";
        for(int j=0;j<matrix[0].size();j++){
            s += to_string(matrix[i][j]);
            if(matrix[i][j]) 
                sf += "0";
            else 
                sf += "1";
        }
        m[s]++;
        m[sf]++;
    }
    int ans = INT_MIN;
    for(auto x: m){
        if(x.second > ans)
            ans = x.second;
    }
    return ans;
}

int main(){   
    vector<vector<int>> matrix{
        {0,0,0},
        {0,0,1},
        {1,1,0}
    };
    cout<<maxEqualRowsAfterFlips(matrix);
	return 0;
}