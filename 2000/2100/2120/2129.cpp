#include "leetcode.h"

class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        int begin = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || title[i] == ' ') {
                if (i - begin > 2) {
                    title[begin] = toupper(title[begin]);
                    ++begin;
                }

                for (int j = begin; j < i; ++j) {
                    title[j] = tolower(title[j]);
                }

                begin = i + 1;
            }
        }

        return title;
    }
};