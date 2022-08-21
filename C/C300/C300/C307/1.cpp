/*
 * @Author: sanjusss
 * @Date: 2022-08-21 10:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-21 10:35:27
 * @FilePath: \C\C300\C300\C307\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        int n = energy.size();
        for (int i = 0; i < n; ++i) {
            initialEnergy -= energy[i];
            if (initialEnergy < 1) {
                ans += 1 - initialEnergy;
                initialEnergy = 1;
            }

            if (initialExperience <= experience[i]) {
                ans += experience[i] + 1 - initialExperience;
                initialExperience = experience[i] + 1;
            }

            initialExperience += experience[i];
        }

        return ans;
    }
};