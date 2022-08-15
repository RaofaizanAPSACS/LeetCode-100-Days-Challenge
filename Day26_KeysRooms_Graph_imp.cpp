/*
Problem link: 
https://leetcode.com/problems/keys-and-rooms/

Problem:
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0.
 Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, 
denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i,
 return true if you can visit all the rooms, or false otherwise.
*/
#include<bits/stdc++.h>
using namespace std;


// graph dfs traversal 
void dfs(int i, vector<bool> &visited,vector<vector<int>> &rooms){
    visited[i] = true;
    cout<< i <<" ";
    for(int k=0;k<rooms[i].size();k++){
        if(!visited[rooms[i][k]])
            dfs(rooms[i][k],visited,rooms);
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size(),false);
    dfs(0,visited,rooms);
    for(auto x: visited)
        if(x == false)
            return false;
    return true;
}
// here nodes representing the rooms numbers
// and the edge between them is representing that the room can be unlocked
int main(){   
    // adjacency list of the graph
    vector<vector<int>> rooms{
        {1,3},
        {3,0,1},
        {2},
        {0}
    };
    cout<<canVisitAllRooms(rooms);
	return 0;
}