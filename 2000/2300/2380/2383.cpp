/*
 * @Author: sanjusss
 * @Date: 2023-03-13 09:06:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-13 09:10:29
 * @FilePath: \2000\2300\2380\2383.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int ene = initialEnergy;
        int exp = initialExperience;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int addEne = max(energy[i] + 1, ene) - ene;
            int addExp = max(experience[i] + 1, exp) - exp;
            ans += addEne + addExp;
            ene += addEne - energy[i];
            exp += addExp + experience[i];
        }

        return ans;
    }
};