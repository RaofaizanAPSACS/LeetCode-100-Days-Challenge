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


bool dfs(map<int, vector<int>> &list, int i, vector<bool> &visited2, vector<bool> &visited){
    if(visited[i] == false){
        visited[i] = true;
        visited2[i] = true;
        for(auto x: list[i]){

            if(!visited[x] and dfs(list, x, visited2, visited) )
                return true;
            else if(visited2[x])
                return true;
        }
    }
    visited2[i] = false;
    return false;
}   
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, vector<int> > adjlist;
    vector<bool> visited(numCourses, false);
    vector<bool> visited2(numCourses, false);

    for(auto x: prerequisites){
        adjlist[x[0]].push_back(x[1]);
    }
    for(auto x: adjlist){
        if(!visited[x.first]  and dfs(adjlist, x.first, visited2, visited))
            return false;
    }
    return true;
}

int main(){
    vector<vector<int> > pre{
        {1,0},{0,2}
    };
    cout<<canFinish(2, pre); 
    return 0;
}