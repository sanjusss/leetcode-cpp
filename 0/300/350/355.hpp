#pragma once
#include "leetcode.h"

//class Twitter 
//{
//    struct Post
//    {
//        int userId;
//        int tweetId;
//    };
//
//public:
//    /** Initialize your data structure here. */
//    Twitter() 
//    {
//
//    }
//
//    /** Compose a new tweet. */
//    void postTweet(int userId, int tweetId)
//    {
//        Post post;
//        post.userId = userId;
//        post.tweetId = tweetId;
//        m_posts.push_back(post);
//    }
//
//    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
//    vector<int> getNewsFeed(int userId)
//    {
//        vector<int> res;
//        for (auto i = m_posts.rbegin(); i != m_posts.rend() && res.size() < 10; ++i)
//        {
//            if (i->userId == userId || m_follows[userId].find(i->userId) != m_follows[userId].end())
//            {
//                res.push_back(i->tweetId);
//            }
//        }
//
//        return res;
//    }
//
//    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
//    void follow(int followerId, int followeeId)
//    {
//        m_follows[followerId].insert(followeeId);
//    }
//
//    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
//    void unfollow(int followerId, int followeeId) 
//    {
//        if (m_follows.find(followerId) != m_follows.end() &&
//            m_follows[followerId].find(followeeId) != m_follows[followerId].end())
//        {
//            m_follows[followerId].erase(followeeId);
//        }
//    }
//
//private:
//    vector<Post> m_posts;
//    unordered_map<int, unordered_set<int>> m_follows;
//};

class Twitter
{
    struct Post
    {
        int userId;
        int tweetId;
    };

public:
    /** Initialize your data structure here. */
    Twitter()
    {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        m_userPosts[userId].push_back(m_posts.size());
        Post post;
        post.userId = userId;
        post.tweetId = tweetId;
        m_posts.push_back(post);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        set<int> posts;
        insertPosts(posts, userId);
        for (int i : m_follows[userId])
        {
            insertPosts(posts, i);
        }

        vector<int> res(posts.rbegin(), posts.rend());
        for (auto i = res.begin(); i != res.end(); ++i)
        {
            *i = m_posts[*i].tweetId;
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        m_follows[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (m_follows.find(followerId) != m_follows.end() &&
            m_follows[followerId].find(followeeId) != m_follows[followerId].end())
        {
            m_follows[followerId].erase(followeeId);
        }
    }

private:
    void insertPosts(set<int>& posts, int userId)
    {
        vector<int>& indeies = m_userPosts[userId];
        for (int i = 0; i < indeies.size() && i < 10; ++i)
        {
            posts.insert(indeies[indeies.size() - i - 1]);
            if (posts.size() > 10)
            {
                posts.erase(posts.begin());
            }
        }
    }

private:
    vector<Post> m_posts;
    unordered_map<int, vector<int>> m_userPosts;
    unordered_map<int, unordered_set<int>> m_follows;
};