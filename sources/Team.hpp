#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace b_ball
{
    class Team
    {

    public:
        string team_name;
        double team_talent;
        int team_result;
        int total_points_wins;
        int total_points_loss;
        int total_win;
        int total_loss;
        int total_remainder_basket;
        vector <int> team_status_in_game;
        Team(string name, double talent) : team_name(name), team_talent(talent){
            team_result = 0;
            total_points_wins = 0;
            total_points_loss=0;
            total_win = 0;
            total_loss = 0;
            total_remainder_basket=0;
        };

        friend ostream &operator<<(ostream &os, const Team &team){
            os << "Total remindar basket: " << team.total_remainder_basket << endl; 
            return os;
        };
};
        };
    //};
