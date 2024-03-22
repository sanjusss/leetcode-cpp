#include "leetcode.h"

class FrequencyTracker {
public:
    FrequencyTracker() {

    }
    
    void add(int number) {
        int& freq = m_k2freq[number];
        m_freq2k[freq].erase(number);
        ++freq;
        m_freq2k[freq].insert(number);
    }
    
    void deleteOne(int number) {
        int& freq = m_k2freq[number];
        if (freq == 0) {
            return;
        }

        m_freq2k[freq].erase(number);
        if (--freq > 0) {
            m_freq2k[freq].insert(number);
        }
    }
    
    bool hasFrequency(int frequency) {
        return frequency > 0 && m_freq2k[frequency].size() > 0;
    }

private:
    unordered_map<int, int> m_k2freq;
    unordered_map<int, unordered_set<int>> m_freq2k;
};