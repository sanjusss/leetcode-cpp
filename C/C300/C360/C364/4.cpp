/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-24 11:53:24
 * @FilePath: \C\C300\C360\C364\4.cpp
 */
#include "leetcode.h"

static vector<int> primes;
static constexpr int maxI = 1e5;
static vector<bool> isPrime(maxI + 1, true);

static int init = [] () {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= maxI; ++i) {
        if (!isPrime[i]) {
            continue;
        }

        primes.push_back(i);
        for (int j = i + i; j <= maxI; j += i) {
            isPrime[j] = false;
        }
    }
    return 0;
} ();

class UnionFind {
public:
    UnionFind(int n) : m_parent(n), m_size(n, 1) {
        for (int i = 0; i < n; ++i) {
            m_parent[i] = i;
        }
    }

    int count(int i) {
        return m_size[find(i)];
    }

    int find(int i) {
        if (m_parent[i] == i) {
            return i;
        }
        else {
            m_parent[i] = find(m_parent[i]);
            return m_parent[i];
        }
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }

        if (m_size[a] > m_size[b]) {
            swap(a, b);
        }

        m_parent[a] = b;
        m_size[b] += m_size[a];
        return true;
    }

private:
    vector<int> m_parent;
    vector<int> m_size;
};

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        UnionFind uf(n + 1);
        vector<vector<int>> conns(n + 1);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
            if (!isPrime[e[0]] && !isPrime[e[1]]) {
                uf.merge(e[0], e[1]);
            }
        }

        int64_t ans = 0;
        for (int i : primes) {
            if (i > n) {
                break;
            }

            int64_t ptsum = 0;
            for (int j : conns[i]) {
                if (isPrime[j]) {
                    continue;
                }

                int64_t p = uf.count(j);
                ans += p + p * ptsum;
                ptsum += p;
            }
        }

        return ans;
    }
};

TEST(&Solution::countPaths)