/*
 * @Author: sanjusss
 * @Date: 2022-06-23 09:26:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-23 09:43:36
 * @FilePath: \0\200\270\271.cpp
 */
#include "leetcode.h"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        ans += encodeSize(strs.size());
        for (auto &s : strs) {
            ans += encodeSize(s.size());
            ans += s;
        }

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        const char* data = s.data();
        size_t n = decodeSize(data);
        data += sizeof(size_t);
        for (size_t i = 0; i < n; ++i) {
            size_t size = decodeSize(data);
            data += sizeof(size_t);
            string& str = ans.emplace_back(size, 0);
            memcpy(str.data(), data, size);
            data += size;
        }

        return ans;
    }

private:
    string encodeSize(size_t size) {
        string res(sizeof(size_t), 0);
        memcpy(res.data(), &size, sizeof(size_t));
        return res;
    }

    size_t decodeSize(const char* data) {
        size_t size;
        memcpy(&size, data, sizeof(size_t));
        return size;
    }
};