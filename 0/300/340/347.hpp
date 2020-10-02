#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) 
//    {
//        unordered_map<int, int> f;
//        for (int i : nums)
//        {
//            ++f[i];
//        }
//
//        multimap<int, int> m;
//        for (auto i : f)
//        {
//            m.insert(make_pair(i.second, i.first));
//        }
//
//        vector<int> results;
//        for (auto i = m.rbegin(); k > 0 && i != m.rend(); ++i, --k)
//        {
//            results.push_back(i->second);
//        }
//
//        return results;
//    }
//};

//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> freqs;
//        for (int i : nums) {
//            ++freqs[i];
//        }
//
//        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) 
//        {
//            return a.second > b.second;
//        };
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
//        for (auto& p : freqs) {
//            if (q.size() < k) {
//                q.push(p);
//            }
//            else if (cmp(p, q.top())) {
//                q.pop();
//                q.push(p);
//            }
//        }
//
//        vector<int> ans;
//        while (!q.empty()) {
//            ans.push_back(q.top().first);
//            q.pop();
//        }
//
//        return ans;
//    }
//};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int i : nums) {
            ++freqs[i];
        }

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) 
        {
            return a.second > b.second;
        };
        vector<pair<int, int>> pairs;
        for (auto& p : freqs) {
            pairs.push_back(p);
        }

        nth_element(pairs.begin(), pairs.begin() + k - 1, pairs.end(), cmp);
        auto begin = pairs.begin();
        auto end = begin + k;
        vector<int> ans;
        for (auto i = begin; i != end; ++i) {
            ans.push_back(i->first);
        }

        return ans;
    }
};