/*
Problem:
Given a sorted array of distinct integers A[1, ..., n], you want to find out whether there
is an index ”i” for which A[i] = i.
For example In [10, 3, 5, 3, 7], A[3] = 3. In [2, 3, 4, 5, 6, 7] there is no such i.
*/
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> array, int l, int h){
    if(l <= h){
        int mid = (l+h)/2;

        if(array[mid] == mid)
            return mid;
        int res = -1;
        if(mid +1 <= array[h])
            res = binarySearch(array, mid+1, h);
        if(res != -1)
            return res;
        if(mid -1 >= array[l])
            return binarySearch(array, l, mid-1);
    }
    return -1;
}

int main(){   
    vector<int> array{1,2,3,4,4};
    cout<<binarySearch(array, 0, array.size()-1);
	return 0;
}