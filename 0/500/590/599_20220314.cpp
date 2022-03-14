/*
 * @Author: sanjusss
 * @Date: 2022-03-14 08:28:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-14 08:36:09
 * @FilePath: \0\500\590\599_20220314.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index;
        for (int i = 0; i < list1.size(); ++i) {
            index[list1[i]] = i;
        }

        int sum = INT_MAX;
        vector<int> is;
        for (int i = 0; i < list2.size(); ++i) {
            auto p = index.find(list2[i]);
            if (p == index.end()) {
                continue;
            }

            if (p->second + i < sum) {
                sum = p->second + i;
                is.clear();
                is.push_back(i);
            }
            else if (p->second + i == sum) {
                is.push_back(i);
            }
        }

        vector<string> ans;
        for (int i : is) {
            ans.push_back(list2[i]);
        }

        return ans;
    }
};