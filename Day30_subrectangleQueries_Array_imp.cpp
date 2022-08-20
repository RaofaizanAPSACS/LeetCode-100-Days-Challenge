/*
Problem link: 
https://leetcode.com/problems/subrectangle-queries/

Problem:
Implement the class SubrectangleQueries which receives a rows x cols rectangle as a matrix of integers in 
the constructor and supports two methods:
1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
Updates all values with newValue in the subrectangle whose upper left coordinate is (row1,col1) and bottom 
right coordinate is (row2,col2).
2. getValue(int row, int col)
Returns the current value of the coordinate (row,col) from the rectangle.
*/
#include<bits/stdc++.h>
using namespace std;

class SubrectangleQueries {
    vector<vector<int>> rectangle;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rectangle = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                rectangle[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rectangle[row][col];
    }
    void display(){
        for(int i=0;i<rectangle.size();i++){
            for(int j=0;j<rectangle[i].size();j++){
                cout<<rectangle[i][j]<<" ";
            }
            cout<<endl;
        }        
    }
};

int main(){
    vector<vector<int>> rec{
        {1,2,1},
        {4,3,4},
        {3,2,1},
        {1,1,1}
    };  
    SubrectangleQueries* obj = new SubrectangleQueries(rec);
    // cout<<obj->getValue(0,2);
    obj->updateSubrectangle(3, 0, 3, 2, 10);
    obj->display();

    return 0;
}