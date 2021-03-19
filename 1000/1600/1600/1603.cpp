#include "leetcode.h"

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) : m_spaces{ 0, big, medium, small } {

    }
    
    bool addCar(int carType) {
        if (m_spaces[carType] > 0) {
            --m_spaces[carType];
            return true;
        }
        else {
            return false;
        }
    }

private:
    vector<int> m_spaces;
};