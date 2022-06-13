#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Schedule.hpp"
#include "Team.hpp"

namespace b_ball
{
    // class Schedule;
    class Leauge
    {

    public:
        Schedule *schedule;
        vector<Team *> teams_Leauge;
        Leauge()
        {

            vector<string> teams_name = {"Lakers", "Warriors", "Cavaliers", "Rockets", "Spurs", "Clippers", "Kings", "Nets", "Pacers", "Hornets", "Timberwolves", "Mavericks", "Grizzlies", "Pelicans", "Raptors", "Thunder", "Trail Blazers", "Jazz", "Nuggets", "Suns"};
            for (size_t i = 0; i < teams_name.size(); i++)
            {
                double num = (double)rand() / (RAND_MAX);
                teams_Leauge.push_back(new Team(teams_name[i], (num))); // ceate a team with random talent, push it to teams_Leauge
            }
            schedule = new Schedule(teams_Leauge);
            cout << "leauge size: " << teams_Leauge.size() << endl;
            
        };

        // operator <<
        friend ostream &operator<<(ostream &os, const Leauge &leauge)
        {
            for (size_t i = 0; i < leauge.teams_Leauge.size(); i++)
            {
                os <<"Name : "<< leauge.teams_Leauge[i]->team_name << " ,talent: " << leauge.teams_Leauge[i]->team_talent << endl;
            }
            return os;
        }

        void show_Statistics(){
            REMINDER_BASKET_Statistic();
            WINS_LOST_Statistic();
            TOP_teams_Statistic(5);
            // cout << *schedule << endl;
        }

        void WINS_LOST_Statistic()
        {

            /* ----------SHOW WINS LOST----------------
            @ sort the teams acoording to the number of wins
            @  */
            cout << "--------------WINS LOST STATISTICS----------------" << endl;
            sort(teams_Leauge.begin(), teams_Leauge.end(), [](Team *a, Team *b)
                 { return a->total_win > b->total_win; });
            for (Team *team : teams_Leauge)
            {
                cout << team->team_name << ","
                     << "total wins: " << team->total_win << endl;
            }
            cout << "----------------------------------------------------" << endl;
        }
        void REMINDER_BASKET_Statistic()
        {
            /* ----------SHOW REMINDER_BASKET----------------
            @ calculate for each team in the leauge the total reminder basket
            @ sort the tems acoordoig to the previous result */
            cout << "--------------REMINDER BASKET STATISTICS----------------" << endl;
            for (Team *team : teams_Leauge)
            {
                team->total_remainder_basket = team->total_points_wins - team->total_points_loss;
            }
            sort(teams_Leauge.begin(), teams_Leauge.end(), [](Team *a, Team *b)
                 { return a->total_remainder_basket > b->total_remainder_basket; });

            // print the vector after sort
            for (Team *team : teams_Leauge)
            {
                cout << team->team_name << " " << team->total_remainder_basket << endl;
            }
            cout << "----------------------------------------------------" << endl;
        }

        void TOP_teams_Statistic(int size)
        {

            /* ----------SHOW TOP TEAMS----------------
            @ print the top teams in the leauge
            @ sort the tems acoordoig to the previous result */
            cout << "--------------TOP TEAMS STATISTICS----------------" << endl;
            sort(teams_Leauge.begin(), teams_Leauge.end(), [](Team *a, Team *b)
                 { return a->total_win > b->total_win; });

            // print the vector after sort
            for (Team *team : teams_Leauge)
            {
                cout << team->team_name << " : total wins-> " << team->total_win << endl;
            
        }
        cout << "----------------------------------------------------" << endl;

        //void long_wins(){}
        }
    };
};
