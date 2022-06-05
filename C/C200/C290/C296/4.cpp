/*
 * @Author: sanjusss
 * @Date: 2022-06-05 10:27:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-05 10:53:22
 * @FilePath: \C\C200\C290\C296\4.cpp
 */
#include "leetcode.h"

class TextEditor {
public:
    TextEditor() {

    }
    
    void addText(string text) {
        m_text.insert(m_cur, text);
        m_cur += text.size();
    }
    
    int deleteText(int k) {
        int toDel = min(m_cur, k);
        m_text.erase(m_cur - toDel, toDel);
        m_cur -= toDel;
        return toDel;
    }
    
    string cursorLeft(int k) {
        m_cur = max<int>(m_cur - k, 0);
        int len = min(10, m_cur);
        return m_text.substr(m_cur - len, len);
    }
    
    string cursorRight(int k) {
        m_cur = min<int>(m_cur + k, m_text.size());
        int len = min(10, m_cur);
        return m_text.substr(m_cur - len, len);
    }

private:
    int m_cur = 0;
    string m_text;
};