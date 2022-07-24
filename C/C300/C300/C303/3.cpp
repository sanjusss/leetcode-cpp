/*
 * @Author: sanjusss
 * @Date: 2022-07-24 10:28:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-24 11:16:26
 * @FilePath: \C\C300\C300\C303\3.cpp
 */
#include "leetcode.h"

vector<string> g_foods;
vector<string> g_cuisines;
vector<int> g_ratings;
unordered_map<string, int> g_f2i;
bool cmp(int a, int b) {
    if (g_ratings[a] == g_ratings[b]) {
        return g_foods[a] < g_foods[b];
    }
    else {
        return g_ratings[a] > g_ratings[b];
    }
}

unordered_map<string, set<int, decltype(&cmp)>> g_highest;

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        g_foods = foods;
        g_cuisines = cuisines;
        g_ratings = ratings;
        g_f2i.clear();
        g_highest.clear();
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            auto& f = foods[i];
            auto& c = cuisines[i];
            g_f2i[f] = i;
            if (!g_highest.count(c)) {
                g_highest.emplace(c, set<int, decltype(&cmp)>(cmp));
            }

            auto& h = g_highest.at(c);
            h.insert(i);
        }
    }

    void changeRating(string food, int newRating) {
        int i = g_f2i[food];
        auto& c = g_cuisines[i];
        auto& h = g_highest.at(c);
        h.erase(i);
        g_ratings[i] = newRating;
        h.insert(i);
    }

    string highestRated(string cuisine) {
        auto& h = g_highest.at(cuisine);
        return g_foods[*h.begin()];
    }
};