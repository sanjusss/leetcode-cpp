/*
 * @Author: sanjusss
 * @Date: 2022-03-18 08:29:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-18 08:33:04
 * @FilePath: \2000\2000\2040\2043.cpp
 */
#include "leetcode.h"

class Bank {
public:
    Bank(vector<long long>& balance) : m_balance(balance) {

    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > m_balance.size() || account2 > m_balance.size()) {
            return false;
        }

        if (m_balance[account1 - 1] < money) {
            return false;
        }

        
        m_balance[account1 - 1] -= money;
        m_balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > m_balance.size()) {
            return false;
        }

        m_balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > m_balance.size()) {
            return false;
        }

        if (m_balance[account - 1] < money) {
            return false;
        }

        m_balance[account - 1] -= money;
        return true;
    }

private:
    vector<long long> m_balance;
};
