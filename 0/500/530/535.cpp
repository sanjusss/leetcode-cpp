#include "leetcode.h"

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = to_string(m_cur++);
        m_s2l[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m_s2l[shortUrl];
    }

private:
    unordered_map<string, string> m_s2l;
    int m_cur = 0;
};