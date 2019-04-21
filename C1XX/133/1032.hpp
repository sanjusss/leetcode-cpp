#pragma once
#include "leetcode.h"

class StreamChecker 
{
    struct CharNode
    {
        ~CharNode()
        {
            for (auto i : children)
            {
                delete i.second;
            }
        }

        map<char, CharNode*> children;
        bool end = false;
    };

public:
    StreamChecker(vector<string>& words) 
    {
        CharNode* head;
        char c;
        for (auto& s : words)
        {
            head = &m_root;
            m_maxLength = max((int)s.length(), m_maxLength);
            for (auto i = s.rbegin(); i != s.rend(); ++i)
            {
                c = *i;
                if (head->children.find(c) == head->children.end())
                {
                    head->children[c] = new CharNode();
                }

                head = head->children[c];
            }

            head->end = true;
        }
    }

    bool query(char letter) 
    {
        m_queries.push_back(letter);
        if (m_queries.size() > m_maxLength)
        {
            m_queries.pop_front();
        }

        CharNode* head = &m_root;
        for (auto i = m_queries.rbegin(); i != m_queries.rend(); ++i)
        {
            if (head->end || head->children.find(*i) == head->children.end())
            {
                return head->end;
            }

            head = head->children[*i];
        }

        return head->end;
    }

private:
    CharNode m_root;
    int m_maxLength = 0;
    list<char> m_queries;
};