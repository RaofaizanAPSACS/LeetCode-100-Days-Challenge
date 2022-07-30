/*
Problem link: 
https://leetcode.com/problems/word-search/

Problem:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Algorithm or Approach :  Backtracking or Recursion

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool searchWord(vector<vector<char>>& board, string word, int i, int j, int k){
    if(k >= word.size()-1){
        return true;
    }
    int temp = board[i][j];
    board[i][j] = '*';

    // right
    if(j+1 < board[0].size() and word[k+1] == board[i][j+1])
        return searchWord(board,word,i,j+1,k+1);
    // down
    if(i+1 < board.size() and word[k+1] == board[i+1][j])
        return searchWord(board,word,i+1,j,k+1);
    // left
    if(j > 0 and word[k+1] == board[i][j-1])
        return searchWord(board,word,i,j-1,k+1);
    // up
    if(i > 0 and word[k+1] == board[i-1][j])
        return searchWord(board,word,i-1,j,k+1);

    board[i][j] = temp; // backtrack
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(word[0] == board[i][j])
                if(searchWord(board, word, i, j, 0))
                    return true; 
        }
    }
    return false;   
}

int main(){
    vector<vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'},
    };
    cout<<exist(board,"ZBCCED");
    return 0;
    
}