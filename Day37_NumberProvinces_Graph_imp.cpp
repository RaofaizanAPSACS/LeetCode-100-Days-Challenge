/*
Problem link: 
https://leetcode.com/problems/number-of-provinces/

Problem:
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
*/
#include<bits/stdc++.h>
using namespace std;

void ToAdjList(vector<vector<int>> &isConnected, vector<vector<int>> &adjList){
    for(int i=0;i<isConnected.size();i++){
        for(int j=0;j<isConnected[0].size();j++){
            if(i != j and isConnected[i][j]){
                adjList[i].push_back(j);
            }
        }
    }
}

void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int k){
    visited[k] = true;
    for(int i=0;i<adjList[k].size();i++){
        if(!visited[adjList[k][i]])
            dfs(adjList, visited, adjList[k][i]);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    vector<vector<int>> adjList(isConnected.size());   
    vector<bool> visited(isConnected.size(), false);
    ToAdjList(isConnected, adjList);
    int count=0;
    for(int i=0;i<isConnected.size();i++){
        if(!visited[i]){
            dfs(adjList, visited, i);
            count++;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> adjMatrix{
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    cout<<findCircleNum(adjMatrix);
    return 0;
}