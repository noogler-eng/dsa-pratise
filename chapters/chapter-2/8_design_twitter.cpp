// Twitter Design 
// QUESTION - https://leetcode.com/problems/design-twitter/description/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

// it gives the TLE
// time complexity O(log n) where n is total tweets
class Twitter {
public:
    vector<vector<int>> users;
    int curr = 0;
    unordered_map<int, set<int>> m;
    // it will take - currId, userid, tweetid
    priority_queue<pair<int, pair<int, int>>> posts;

    Twitter() {
        this->users.clear();
        this->curr = 0;
        this->posts = priority_queue<pair<int, pair<int, int>>>();
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push({curr, {userId, tweetId}});
        curr++;
    }
    
    // returning the tweet id
    vector<int> getNewsFeed(int userId) {
        vector<int> feeds;
        priority_queue<pair<int, pair<int, int>>> temp = this->posts;
        int n = 0;
        while(!temp.empty() && n < 10){
            int thisUserId = temp.top().second.first;
            int tweetId = temp.top().second.second;
            temp.pop();

            if(userId == thisUserId || m[userId].count(thisUserId) != 0){
                feeds.push_back(tweetId);
                n++;
            }
        }
        return feeds;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m[followerId].erase(followeeId);
    }
};


// time complexity O(k * u log(k * u)) where k is the 10 tweets in priority queue and u is no od follwers
class Twitter {
public:
    vector<vector<int>> users;
    int curr = 0;
    unordered_map<int, set<int>> m;
    // it will take - currId, userid, tweetid
    unordered_map<int, vector<pair<int, int>>> posts;

    Twitter() {
        this->users.clear();
        this->curr = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({curr, tweetId});
        curr++;
    }
    
    // returning the tweet id
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> feed;
        for(auto tweet: posts[userId]){
            feed.push(tweet);
        }

        for(auto i: m[userId]){
            for(auto tweet: posts[i]){
                feed.push(tweet);
            }
        }


        int n = 0;
        vector<int> ans;
        while(!feed.empty() && n < 10){
            ans.push_back(feed.top().second);
            feed.pop();
            n++;
        } 
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(m[followerId].find(followeeId) != m[followerId].end()){
            m[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */