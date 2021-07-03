/*
 * @Author: sanjusss
 * @Date: 2021-07-01 08:13:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-01 08:55:56
 * @FilePath: \D\D000\D55\4.cpp
 */
#include "leetcode.h"

class MovieRentingSystem {
private:
    static constexpr int64_t key(int shop, int movie) {
        return ((int64_t)shop << 32) + (int64_t)movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];
            m_Prices[key(shop, movie)] = price;
            m_Movies[movie].emplace(price, shop);
        }
    }
    
    vector<int> search(int movie) {
        auto mp = m_Movies.find(movie);
        if (mp == m_Movies.end()) {
            return {};
        }

        vector<int> res;
        auto& shops = mp->second;
        for (auto i = shops.begin(); res.size() < 5 && i != shops.end(); ++i) {
            res.emplace_back(get<1>(*i));
        }

        return res;
    }
    
    void rent(int shop, int movie) {
        int price = m_Prices[key(shop, movie)];
        m_Rents.emplace(price, shop, movie);
        m_Movies[movie].erase({ price, shop });
    }
    
    void drop(int shop, int movie) {
        int price = m_Prices[key(shop, movie)];
        m_Rents.erase({ price, shop, movie });
        m_Movies[movie].emplace(price, shop);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto i = m_Rents.begin(); res.size() < 5 && i != m_Rents.end(); ++i) {
            auto& [_, shop, movie] = *i;
            res.emplace_back(vector<int>({ shop, movie }));
        }

        return res;
    }   

private:
    set<tuple<int, int, int>> m_Rents;//已借出的 price, shop, movie
    unordered_map<int, set<tuple<int, int>>> m_Movies;//所有未借出的电影 movie, price, shop
    unordered_map<int64_t, int> m_Prices;//所有电影的价格
};