/*
 * @Author: sanjusss
 * @Date: 2021-07-26 12:00:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-06 09:50:05
 * @FilePath: \解题模板\自定义hash.h
 */
#include "leetcode.h"

template <typename T>
inline void hash_combine(size_t& seed, const T& val) {
    seed ^= hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std {
template <class T1, class T2>
struct hash<std::pair<T1, T2>> {
    inline size_t operator()(const pair<T1, T2>& v) const {
        size_t res = hash<T1>()(p.first);
        hash_combine(res, p.second);
        return res;
    }
};
}  // namespace std

template <class T1, class T2>
struct pair_hash {
    inline size_t operator()(const pair<T1, T2>& p) const {
        size_t res = hash<T1>()(p.first);
        hash_combine(res, p.second);
        return res;
    }
};