#include "leetcode.h"

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        unordered_map<string, int> s2i;
        for (int i = 0; i < m; ++i) {
            s2i[req_skills[i]] = i;
        }


        int allMask = 1 << m;
        int endMask = allMask - 1;
        int n = people.size();
        vector<int> count(allMask, n);
        count[0] = 0;
        vector<int> prevSkill(allMask);
        vector<int> prevPerson(allMask);
        for (int i = 0; i < n; ++i) {
            int own = 0;
            for (auto& s : people[i]) {
                own |= 1 << (s2i[s]);
            }
            
            if (own == 0) {
                continue;
            }

            for (int prev = 0; prev < endMask; ++prev) {
                int cur = prev | own;
                if (count[cur] > count[prev] + 1) {
                    count[cur] = count[prev] + 1;
                    prevSkill[cur] = prev;
                    prevPerson[cur] = i;
                }
            }
        }

        vector<int> ans;
        for (int i = endMask; i > 0; i = prevSkill[i]) {
            ans.push_back(prevPerson[i]);
        }

        return ans;
    }
};