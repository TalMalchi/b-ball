#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Game.hpp"


namespace b_ball
{

    class Schedule
    {

    public:

        vector<Game*> games;
        Schedule(vector<Team *> teams_Leauge)
        {
            for (size_t i = 0; i < teams_Leauge.size(); i++)
            {
                for (size_t j = i + 1; j < teams_Leauge.size(); j++)
                {
                    games.push_back(new Game(teams_Leauge[i],teams_Leauge[j]));
                    games.push_back(new Game(teams_Leauge[j],teams_Leauge[i]));
                }
            }
        };
        Schedule(){};
        // operator <<
        friend ostream &operator<<(ostream &os, const Schedule &schedule)
        {
            for (size_t i = 0; i < schedule.games.size(); i++)
            {
                os << *schedule.games[i] << endl;
            }
            return os;
        }


 
    };
};
