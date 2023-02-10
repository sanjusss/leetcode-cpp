/*
 * @Author: sanjusss
 * @Date: 2023-02-10 13:41:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-10 13:47:36
 * @FilePath: \1000\1700\1790\1797.cpp
 */
#include "leetcode.h"

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) : m_TimeToLive(timeToLive) {
    }

    void generate(string tokenId, int currentTime) {
        ids[tokenId] = currentTime + m_TimeToLive;
        times.insert(currentTime + m_TimeToLive);
    }

    void renew(string tokenId, int currentTime) {
        if (!ids.count(tokenId) || ids[tokenId] <= currentTime) {
            return;
        }

        times.erase(ids[tokenId]);
        ids[tokenId] = currentTime + m_TimeToLive;
        times.insert(currentTime + m_TimeToLive);
    }

    int countUnexpiredTokens(int currentTime) {
        while (!times.empty() && *times.begin() <= currentTime) {
            times.erase(times.begin());
        }

        return times.size();
    }

private:
    const int m_TimeToLive;
    unordered_map<string, int> ids;
    set<int> times;
};
