/*
Problem link: 
https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

Problem:
Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array 
bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, 
consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.
*/
#include<bits/stdc++.h>
using namespace std;


int numberOfBeams(vector<string>& bank) {
    vector<int> devices;
    int ans=0;
    for(int i=0;i<bank.size();i++){
        int count=0;
        for(int j=0;j<bank[0].size();j++){
            if(bank[i][j] == '1')
                count++;
        }
        if(count != 0)
            devices.push_back(count);
    }
    for(int i=1;i<devices.size();i++){
        ans += (devices[i-1]*devices[i]);
    }
    return ans;
}

int main(){   
    vector<string> bank{"011001","000000","010100","001000"};
    cout<<numberOfBeams(bank);
	return 0;
}