/*
 * @Author: sanjusss
 * @Date: 2021-06-08 13:50:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-08 14:35:07
 * @FilePath: \0\0\70\71.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string simplifyPath(string path) {
//         string_view sv = path;
//         string::size_type cur = 0;
//         string::size_type next;
//         vector<string_view> all;
//         while (true) {
//             next = sv.find('/', cur + 1);
//             string_view sub = next == string::npos ? sv.substr(cur + 1) : sv.substr(cur + 1, next - cur - 1);
//             if (sub == ".."sv) {
//                 if (!all.empty()) {
//                     all.pop_back();
//                 }
//             }
//             else if (sub != "."sv && !sub.empty()) {
//                 all.push_back(sub);
//             }

//             if (next == string::npos) {
//                 break;
//             }
//             else {
//                 cur = next;
//             }
//         }
        
//         string ans;
//         for (auto& i : all) {
//             ans.push_back('/');
//             ans += i;
//         }

//         return ans.empty() ? "/"s : ans;
//     }
// };

class Solution {
public:
    string simplifyPath(string path) {
        string_view sv = path;
        string::size_type cur = 0;
        string::size_type next;
        stack<string::size_type> st;
        st.push(0);
        int i = 0;
        while (true) {
            next = sv.find('/', cur + 1);
            string_view sub = next == string::npos ? sv.substr(cur + 1) : sv.substr(cur + 1, next - cur - 1);
            if (sub == ".."sv) {
                if (st.size() > 1) {
                    st.pop();
                }

                i = st.top();
            }
            else if (sub != "."sv && !sub.empty()) {
                for (char c : sub) {
                    path[++i] = c;
                }

                path[++i] = '/';
                st.push(i);
            }

            if (next == string::npos) {
                break;
            }
            else {
                cur = next;
            }
        }

        path.resize(max(i, 1));
        return path;
    }
};

TEST(&Solution::simplifyPath)