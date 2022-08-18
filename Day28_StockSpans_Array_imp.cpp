/*
Problem link: 
https://leetcode.com/problems/online-stock-span/

Problem:
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's
 price for the current day.
The span of the stock's price today is defined as the maximum number of consecutive days (starting from 
today and going backward) for which the stock price was less than or equal to today's price.
For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock 
spans would be [1,1,1,2,1,4,6].
*/
#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
    vector<int> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=1;
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i] > price) break;
            count++;
        }
        prices.push_back(price);
        return count;
    }
};
class StockSpanners {
    stack<pair<int,int>> st;
public:
    StockSpanners() {
        
    }
    int next(int price) {
        int count=1;
        while(!st.empty() and st.top().first <= price){
            count += st.top().second;
            st.pop();
        }
        st.push(pair(price,count));
        return count;
    }
};

int main(){   
    StockSpanners* obj = new StockSpanners();
    cout<<obj->next(100);
    cout<<obj->next(80);
    cout<<obj->next(60);
    cout<<obj->next(90);
    cout<<obj->next(95);
    cout<<obj->next(70);
	return 0;
}