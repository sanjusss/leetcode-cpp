#pragma once
#include "leetcode.h"

class UndergroundSystem 
{
    struct Trip
    {
        long total = 0;
        int times = 0;
    };

public:
    UndergroundSystem() 
    {

    }

    void checkIn(int id, string stationName, int t) 
    {
        m_ins[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) 
    {
        Trip& trip = m_trips[m_ins[id].first][stationName];
        trip.total += t - m_ins[id].second;
        ++trip.times;
    }

    double getAverageTime(string startStation, string endStation) 
    {
        Trip& trip = m_trips[startStation][endStation];
        return (double)trip.total / (double)trip.times;
    }

private:
    unordered_map<int, pair<string, int>> m_ins;// int id, string stationName, int t
    unordered_map<string, unordered_map<string, Trip>> m_trips;
};