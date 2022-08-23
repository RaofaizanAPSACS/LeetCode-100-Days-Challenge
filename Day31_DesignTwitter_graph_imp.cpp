/*
Problem link: 
https://leetcode.com/problems/design-twitter/

Problem:
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is 
able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
*/
#include<bits/stdc++.h>
using namespace std;
# define max_users 500

class Compare{
public:
    bool operator()(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) const{
        return a.second.first > b.second.first;
    }
};

class user{
public:
    int id;
    unordered_map<int, int> followersId;
    set<pair<int,pair<int,int>>, Compare> activity; 
    vector<pair<int,int>> act;

    user(int id): id(id){
    }
};

class Twitter {
    user* users[max_users];
    int count;
public:
    Twitter() {
        count=0;
        for(int i=0;i<500;i++)
            users[i] = NULL;
    }
    void postTweet(int userId, int tweetId) {
        count++;
        if(users[userId-1] == NULL){
            users[userId-1] = new user(userId);
        }
        users[userId-1]->activity.insert(pair(userId, pair(count, tweetId)));
        users[userId-1]->act.push_back(pair(count,tweetId));

        for(auto x: users[userId-1]->followersId){
            users[x.first-1]->activity.insert(pair(userId , pair(count,tweetId)));
        }
    }
    void filltweet(int uid){
        for(auto x: users[uid-1]->followersId){
            for(auto itr: users[x.first-1]->activity)
                users[uid-1]->activity.insert(itr);
        }
    }
    vector<int> getNewsFeed(int userId){
        vector<int> ans;
        if(users[userId-1] == NULL or users[userId-1]->activity.empty()) return ans;
        filltweet(userId);
        set<pair<int,pair<int,int> >>::iterator it; 
        it = users[userId-1]->activity.begin();
        for(int i=0;i<10;i++){
            pair<int,pair<int,int>> v = *it;
            if(v.first == userId or users[userId-1]->followersId.find(v.first) != users[userId-1]->followersId.end())
                ans.push_back(v.second.second);
            it++;
            if(it == users[userId-1]->activity.end()) break;
        }
        return ans;
    }
    void shiftActivities(int f1, int f2){ 
        if(users[f1-1]->activity.empty() and users[f2-1]->activity.empty()) return;
        for(auto itr: users[f2-1]->activity){
            users[f1-1]->activity.insert(itr);
        }
    }
    void follow(int followerId, int followeeId) {
        if(users[followerId-1] == NULL)
            users[followerId-1] = new user(followerId);
        if(users[followeeId-1] == NULL)
            users[followeeId-1] = new user(followeeId);

        users[followerId-1]->followersId[followeeId] = followerId;
        // users[followeeId-1]->followersId[followerId] = followeeId;
        shiftActivities(followerId, followeeId);
    }
    // remove followers from the list
    void unfollow(int followerId, int followeeId) {
        users[followerId-1]->followersId.erase(followeeId);
        // users[followeeId-1]->followersId.erase(followerId);
        for(int i=0;i<users[followerId-1]->act.size();i++){
            users[followerId-1]->activity.insert(pair(followerId,users[followerId-1]->act[i]));
        }
    }
};

int main(){   
    Twitter* obj = new Twitter();
    obj->postTweet(1,5);
    obj->postTweet(1,4);
    obj->postTweet(2,6);
    obj->postTweet(1,7);
    obj->postTweet(2,234);
    obj->postTweet(1,65);
    obj->postTweet(2,575);
    obj->postTweet(2,23);
    vector<int> ans = obj->getNewsFeed(1);
    for(auto x: ans)
        cout<<x<<" ";
    obj->follow(1,2);
    ans = obj->getNewsFeed(1);
    for(auto x: ans)
        cout<<x<<" ";
    obj->unfollow(1,2);
    ans = obj->getNewsFeed(1);
    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}