/*
Problem link: 
https://leetcode.com/problems/spiral-matrix-ii/

Problem:
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// print the matrix
void display(vector<vector<int>> &matrix){
    for(auto x: matrix){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
// get the first value and delete it 
int getFirstValue(vector<int> &values){
    int temp = values[0];
    values.erase(values.begin());
    return temp;
}
// fill the matrix in spiral way recursively
void fillMatrix(int** matrix, vector<int> &values, int S, int E){
    if(values.empty()){ // base case
        return;
    }
    else{
        // top row
        for(int k=S;k<E;k++)
            matrix[S][k] = getFirstValue(values);
        S++;
        // right column
        for(int k=S;k<E;k++)
            matrix[k][E-1] = getFirstValue(values);
        S--; E--;
        // bottom row
        for(int k=E-1;k>=S;k--)
            matrix[E][k] = getFirstValue(values);
        // left column
        for(int k=E-1;k>S;k--)
            matrix[k][S] = getFirstValue(values);
        fillMatrix(matrix, values, S+1, E); // recursive call
    }
}
// copy the 2d dynamic array into 2d vector
vector<vector<int>> copy(int **matrix,int n){
    vector<vector<int>> mat(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i].push_back(matrix[i][j]);
        }
    }
    return mat;
}
// main function that calls all up function to generate the square matrix in spiral way of size n
vector<vector<int>> generateMatrix(int n){
    vector<int> values;
    int **matrix;
    matrix = new int*[n];
    for(int i = 0; i < n; i++)
        matrix[i] = new int[n];
    for(int i=1;i<=n*n;i++)
        values.push_back(i);
    fillMatrix(matrix, values, 0, n);
    return copy(matrix, n);    
}

int main(){
    vector<vector<int> > matrix;
    matrix = generateMatrix(5);
    display(matrix);
    return 0;
    
}