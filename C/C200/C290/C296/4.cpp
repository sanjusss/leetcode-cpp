/*
 * @Author: sanjusss
 * @Date: 2022-06-05 10:27:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-05 14:05:51
 * @FilePath: \C\C200\C290\C296\4.cpp
 */
#include "leetcode.h"

// class TextEditor {
// public:
//     TextEditor() {

//     }
    
//     void addText(string text) {
//         m_text.insert(m_cur, text);
//         m_cur += text.size();
//     }
    
//     int deleteText(int k) {
//         int toDel = min(m_cur, k);
//         m_text.erase(m_cur - toDel, toDel);
//         m_cur -= toDel;
//         return toDel;
//     }
    
//     string cursorLeft(int k) {
//         m_cur = max<int>(m_cur - k, 0);
//         int len = min(10, m_cur);
//         return m_text.substr(m_cur - len, len);
//     }
    
//     string cursorRight(int k) {
//         m_cur = min<int>(m_cur + k, m_text.size());
//         int len = min(10, m_cur);
//         return m_text.substr(m_cur - len, len);
//     }

// private:
//     int m_cur = 0;
//     string m_text;
// };

class TextEditor {
public:
    TextEditor() {
        m_cur = m_text.begin();
    }
    
    void addText(string text) {
        for (char i : text) {
            m_cur = next(m_text.insert(m_cur, i));
        }
    }
    
    int deleteText(int k) {
        int ans = 0;
        while (m_cur != m_text.begin() && k > 0) {
            --k;
            ++ans;
            m_cur = m_text.erase(prev(m_cur));
        }

        return ans;
    }
    
    string cursorLeft(int k) {
        while (k > 0 && m_cur != m_text.begin()) {
            m_cur--;
            k--;
        }

        return less10();
    }
    
    string cursorRight(int k) {
        while (k > 0 && m_cur != m_text.end()) {
            m_cur++;
            k--;
        }

        return less10();
    }

private:
    string less10() {
        string ans;
        auto i = m_cur;
        int j = 0;
        while (i != m_text.begin() && j < 10) {
            ++j;
            ans.push_back(*(--i));
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    list<char> m_text;
    list<char>::iterator m_cur;
};