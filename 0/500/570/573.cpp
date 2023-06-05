#include "leetcode.h"

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0;
        int dist = INT_MAX;
        for (auto& nut : nuts) {
            int single = abs(tree[0] - nut[0]) + abs(tree[1] - nut[1]);
            sum += single * 2;
            dist = min(dist, abs(squirrel[0] - nut[0]) + abs(squirrel[1] - nut[1]) - single);
        }

        return sum + dist;
    }
};