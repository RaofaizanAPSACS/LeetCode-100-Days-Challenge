/*
Problem link: 
https://leetcode.com/problems/course-schedule/

Problem:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.


*/
#include<bits/stdc++.h>
using namespace std;


void dfs(map<int, vector<int>> &list, int i, bool &isCycle, vector<bool> visited){
    if(visited[i]){
        isCycle = true;
        return;
    }
    visited[i] = true;
    for(auto x: list[i]){
        dfs(list, x, isCycle, visited);
    }
}   
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, vector<int> > adjlist;
    vector<bool> visited(numCourses, false);
    bool isCycle = false;

    for(auto x: prerequisites){
        adjlist[x[0]].push_back(x[1]);
    }
    for(auto x: adjlist){
        dfs(adjlist, x.first, isCycle, visited);
    }
    return !isCycle;
}

int main(){
    vector<vector<int> > pre{
        {1,0},{0,1}
    };
    cout<<canFinish(2, pre); 
    return 0;
}