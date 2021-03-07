#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> isPartition(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    isPartition[i][j] = isPartition[i + 1][j - 1];
                }
                else {
                    isPartition[i][j] = false;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string_view> cur;
        dfs(s, n, isPartition, ans, cur, 0);
        return ans;
    }

private:
    void dfs(string_view s, int n, const vector<vector<bool>>& isPartition, vector<vector<string>>& ans, vector<string_view>& cur, int i) {
        if (i == n) {
            vector<string> line;
            line.reserve(cur.size());
            for (auto& sv : cur) {
                line.emplace_back(sv);
            }

            ans.push_back(move(line));
            return;
        }

        for (int j = i; j < n; ++j) {
            if (!isPartition[i][j]) {
                continue;
            }

            cur.push_back(s.substr(i, j - i + 1));
            dfs(s, n, isPartition, ans, cur, j + 1);
            cur.pop_back();
        }
    }
};

inline void prepare(vector<vector<string>>& arr, std::any&) {
    for (auto& i : arr) {
        sort(i.begin(), i.end());
    }

    sort(arr.begin(), arr.end());
}

TEST_EQUIVALENT_PRE(&Solution::partition, &prepare)