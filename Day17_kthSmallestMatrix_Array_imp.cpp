/*
Problem link: 
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Problem:
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

Algorithm or Approach :  Used priority_queue or Max heap 

*/
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> q;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++)
            q.push(matrix[i][j]);
    }
    int temp = (matrix.size()*matrix.size()) - k;
    for(int i=temp;i>0;i--)
        q.pop();
    return q.top();
}

int main(){ 
    vector<vector<int>> matrix{
        {1,2,3},
        {4,6,7},
        {5,8,9}
    };
    cout<<kthSmallest(matrix,3);
    return 0;
}