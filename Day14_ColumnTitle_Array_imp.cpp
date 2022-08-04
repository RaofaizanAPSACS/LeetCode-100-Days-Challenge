/*
Problem link: 
https://leetcode.com/problems/excel-sheet-column-title/

Problem:
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

Algorithm or Approach :  --

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void findTitle(int temp,string &res){
    if(temp <= 26){
        res += (temp-1) + 'A';
        return;
    }
    else{
        findTitle(temp/26,res); // recursive call
        res += ((temp%26)-1) + 'A';
    }
}
string convertToTitle(int columnNumber){
    string res="";
    if(columnNumber%26 != 0)
        findTitle(columnNumber,res);
    else{
        findTitle(columnNumber-1,res);
        res[res.size()-1] = 'Z';
    }
    return res;
}
int main(){ 
    cout<<convertToTitle(703);
    return 0;
}