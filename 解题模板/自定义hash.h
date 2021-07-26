/*
 * @Author: sanjusss
 * @Date: 2021-07-26 12:00:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-26 12:01:19
 * @FilePath: \解题模板\自定义hash.h
 */
#include <functional>

template <typename T>
inline void hash_combine(std::size_t& seed, const T& val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}