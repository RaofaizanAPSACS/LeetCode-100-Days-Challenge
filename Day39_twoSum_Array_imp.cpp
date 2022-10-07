/*

Problem:
Suppose there are two unsorted sequences of integers i-e A and B. You need to deter-
mine if there is an integer ”a” in sequence A and an integer ”b” in sequence B such

that x=a+b. ”x” can be taken as an input by user. Output will be ”a” and ”b” that
are making ”x” (or you can also return indexes of a and b as an output). Otherwise
output will be ”Not possible”
*/
#include<bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(vector<int> a, vector<int> b, int x){
    int temp;
    pair<int,int> res;
    map<int, bool> bmap;
    for(int i=0;i<b.size();i++){
        bmap[b[i]] = true;
    }
    for(int i=0;i<a.size();i++){
        temp = x - a[i];
        if(bmap[temp]){
            res.first = a[i];
            res.second = temp;
            break;
        }
    }
    return res;
}

int main(){  
    pair<int,int> p;
    vector<int> a{3,5,2,3}, b{5,1,6,2};
    p = twoSum(a,b,10);
    cout<<p.first<<"+"<<p.second;
    return 0;
}