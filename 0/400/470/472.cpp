#include "leetcode.h"

class Solution {
    struct Trie {
        // virtual ~Trie() {
        //     for (auto& i : children) {
        //         delete i;
        //         i = nullptr;
        //     }
        // }

        array<Trie*, 26> children = { 0 };
        bool end = false;
    };

    class TrieRoot : public Trie {
    public:
        TrieRoot(int n) : m_inStack(n) {
            m_st.reserve(n);
        }

        bool insert(const string& s) {
            Trie* cur = this;
            int n = s.size();
            int t;
            m_st.clear();
            fill(m_inStack.begin(), m_inStack.begin() + n, false);
            for (int i = 0; i < n; ++i) {
                if (cur->end) {
                    m_st.push_back(i);
                    m_inStack[i] = true;
                }

                t = s[i] - 'a';
                if (cur->children[t] == nullptr) {
                    cur->children[t] = new Trie();
                }

                cur = cur->children[t];
            }

            cur->end = true;
            while (!m_st.empty()) {
                int i = m_st.back();
                m_st.pop_back();
                cur = this;
                while (i < n) {
                    t = s[i] - 'a';
                    if (cur->children[t] == nullptr) {
                        break;
                    }
                    
                    cur = cur->children[t];
                    ++i;
                    if (cur->end && !m_inStack[i]) {
                        m_st.push_back(i);
                        m_inStack[i] = true;
                    }
                }

                if (i == n && cur->end) {
                    return true;
                }
            }

            return false;
        }

    private:
        vector<int> m_st;
        vector<bool> m_inStack;
    };

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        vector<int> indeies(n);
        for (int i = 0; i < n; ++i) {
            indeies[i] = i;
        }

        sort(indeies.begin(), indeies.end(), [&words](int a, int b) {
            return words[a].size() < words[b].size();
        });

        vector<string> ans;
        TrieRoot trie(words[indeies.back()].size());
        for (int i : indeies) {
            if (!words[i].empty() && trie.insert(words[i])) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }   
};

TEST_EQUIVALENT(&Solution::findAllConcatenatedWordsInADict)