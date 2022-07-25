/*
Problem link: 
https://leetcode.com/problems/integer-to-roman/

Problem:
Given an integer, convert it to a roman numeral.

Algorithm or Approach :  --

*/
#include<bits/stdc++.h>
using namespace std;

pair<string,int> RomanMapping(int n){
    if(n >= 1 and n < 5)
        return pair("I",1);
    else if(n >= 5 and n < 10)
        return pair("V",5);
    else if(n >= 10 and n < 50)
        return pair("X",10);
    else if(n >= 50 and n < 100)
        return pair("L",50);
    else if(n >= 100 and n < 500)
        return pair("C",100);
    else if(n >= 500 and n < 1000)
        return pair("D",500);
    else if(n >= 1000)
        return pair("M",1000);
    else 
        return pair("",0);
}

pair<string, int> specialCases(int n){
    if(n == 4)
        return pair("IV",4);
    else if(n == 9)
        return pair("IX",9);
    else if(n >= 40 and n < 50)
        return pair("XL",40);
    else if(n >= 90 and n < 100)
        return pair("XC",90);
    else if(n >= 400 and n < 500)
        return pair("CD",400);
    else if(n >= 900 and  n < 1000)
        return pair("CM",900);
    else 
        return pair("",0);
}

string integerToRoman(int n){
    string ans = "";
    int rem = n;
    pair<string, int> out;
    while(rem){
        
        if(specialCases(rem).second != 0)
            out = specialCases(rem);
        else
            out = RomanMapping(rem);
            
        ans += out.first;
        rem -= out.second;
    }
    return ans;
}

int main(){
    cout<<integerToRoman(3990);
    return 0;
}