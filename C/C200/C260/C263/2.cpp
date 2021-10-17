/*
 * @Author: sanjusss
 * @Date: 2021-10-17 10:29:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-17 10:40:57
 * @FilePath: \C\C200\C260\C263\2.cpp
 */
#include "leetcode.h"

class Bank {
public:
    Bank(vector<long long>& balance) : m_balance(balance) {

    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 <= 0 || account1 > m_balance.size()) {
            return false;
        }

        if (account2 <= 0 || account2 > m_balance.size()) {
            return false;
        }

        if (m_balance[account1 - 1] >= money) {
            m_balance[account1 - 1] -= money;
            m_balance[account2 - 1] += money;
            return true;
        }
        else {
            return false;
        }
    }
    
    bool deposit(int account, long long money) {
        if (account <= 0 || account > m_balance.size()) {
            return false;
        }

        m_balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account <= 0 || account > m_balance.size()) {
            return false;
        }

        if (m_balance[account - 1] >= money) {
            m_balance[account - 1] -= money;
            return true;
        }
        else {
            return false;
        }
    }

private:
    vector<long long> m_balance;
};