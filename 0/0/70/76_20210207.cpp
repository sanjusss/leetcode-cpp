#include "leetcode.h"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tcnt;
        for (char i : t) {
            ++tcnt[i];
        }

        unordered_map<char, int> scnt;
        string_view sv = s;
        string_view ans = sv.substr(0, 0);
        int left = 0;
        int right = 0;
        int n = sv.size();
        while (right < n) {
            if (tcnt.find(sv[right]) != tcnt.end()) {
                ++scnt[sv[right]];
                if (ans.empty()) {
                    if (scnt.size() == tcnt.size() && scnt[sv[right]] == tcnt[sv[right]]) {
                        bool success = true;
                        for (const auto& [i, cnt] : tcnt) {
                            if (scnt[i] < cnt) {
                                success = false;
                                break;
                            }
                        }

                        if (success) {
                            ans = sv.substr(0, right + 1);
                        }
                    }
                }

                if (!ans.empty()) {
                    while (left <= right) {
                        auto pos = scnt.find(sv[left]);
                        if (pos == scnt.end()) {
                            ++left;
                        }
                        else if (pos->second > tcnt[pos->first]) {
                            ++left;
                            --pos->second;
                        }
                        else {
                            break;
                        }
                    }

                    if (right - left + 1 < ans.size()) {
                        ans = sv.substr(left, right - left + 1);
                    }
                }
            }

            ++right;
        }

        return string(ans);
    }
};

TEST(&Solution::minWindow)