/*
Problem link: 
https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/

Problem:
Given two integer arrays startTime and endTime and given an integer queryTime.
The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].
Return the number of students doing their homework at time queryTime. 
More formally, return the number of students 
where queryTime lays in the interval [startTime[i], endTime[i]] inclusive.

Algorithm or Approach :  --

*/
#include<bits/stdc++.h>
using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int count=0;
    for(int i=0;i<startTime.size();i++){
        if(queryTime >= startTime[i] and queryTime <= endTime[i]){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> st,et;
    st.push_back(4);
    // st.push_back(2);
    // st.push_back(3);

    et.push_back(4);
    // et.push_back(2);
    // et.push_back(7);

    cout<<busyStudent(st,et,4);
    

    return 0;
}