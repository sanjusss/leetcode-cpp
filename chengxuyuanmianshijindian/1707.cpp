#include "leetcode.h"

class Solution {
    struct UnionFind {
        UnionFind(unordered_map<string_view, int>&& cnt) : size(cnt) {
            for (auto& [i, _] : cnt) {
                parent[i] = i;
            }
        }

        string_view find(string_view i) {
            auto p = parent.find(i);
            if (p == parent.end()) {
                parent[i] = i;
                size[i] = 0;
                return i;
            }
            else if (p->second == i) {
                return i;
            }
            else {
                p->second = find(p->second);
                return p->second;
            }
        }

        bool merge(string_view a, string_view b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return false;
            }

            if (a > b) {
                swap(a, b);
            }

            parent[b] = a;
            size[a] += size[b];
            size.erase(b);
            return true;
        }

        unordered_map<string_view, int> size;
        unordered_map<string_view, string_view> parent;
    };

public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        unordered_map<string_view, int> cnt;
        for (auto& n : names) {
            string_view sv = n;
            auto p = sv.find('(');
            string_view name = sv.substr(0, p);
            int count = 0;
            ++p;
            while (sv[p] != ')') {
                count = count * 10 + sv[p] - '0'; 
                ++p;
            }

            cnt[name] = count;
        }

        UnionFind uf(move(cnt));
        for (auto& i : synonyms) {
            string_view sv = i;
            auto p = sv.find(',');
            string_view a = sv.substr(1, p - 1);
            string_view b = sv.substr(p + 1, sv.length() - p - 2);
            uf.merge(a, b);
        }

        vector<string> ans;
        for (auto& [s, c] : uf.size) {
            ans.emplace_back(s);
            ans.back() += "(" + to_string(c) + ")";
        }

        return ans;
    }
};

TEST_EQUIVALENT(Solution::trulyMostPopular)