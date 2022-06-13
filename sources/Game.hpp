
#pragma once
#include <iostream>
#include <string>
#include <random>
using namespace std;
#include "Team.hpp"

#define Max_Points 100
#define Min_Points_Home_Team 55
#define Standart_devision_home 13.275918047352
#define Min_Points_Outside_Team 50
#define Standart_devision_outside 14.71960144388
static default_random_engine ran;

namespace b_ball
{

    class Game
    {
    public:
        Team *team_home;
        Team *team_outside;
        string winner;

        unsigned int result;

        Game(Team *team_home, Team *team_outside) : team_home(team_home), team_outside(team_outside)
        {
            result = 0;
            winner = "";

            start_game();
        };
        Game(){};

        void start_game()
        {
            /* --------Home Team-------
            random result according to normal distribution, and add more point according to the team_home's talent */
            normal_distribution<double> dist_Home(77.5, Standart_devision_home);
            team_home->team_result = dist_Home(ran);
            team_home->team_result += team_home->team_talent * 10;
            /* ------Outside Team----
            random result according to normal distribution, and add more point according to the team_home's talent */
            normal_distribution<double> dist_Outside(75, Standart_devision_outside);
            team_outside->team_result = dist_Outside(ran);
            team_outside->team_result += team_outside->team_talent * 10;
            is_winner();
        }
        void is_winner()
        {
            if (team_home->team_result > team_outside->team_result)
            {
                winner = team_home->team_name;
                team_home->total_win++;
                team_home->total_points_wins += team_home->team_result;
                team_home->team_status_in_game.push_back(1);    // for statistic. how many times team_home win time after time
                team_outside->team_status_in_game.push_back(0); // for statistic. how many times team_outside lost time after time
                team_outside->total_points_loss += team_outside->team_result;
                team_outside->total_loss++;
            }
            else if (team_home->team_result < team_outside->team_result)
            {
                winner = team_outside->team_name;
                team_outside->total_win++;
                team_outside->total_points_wins += team_outside->team_result;
                team_home->team_status_in_game.push_back(0);
                team_outside->team_status_in_game.push_back(1);
                team_home->total_points_loss += team_home->team_result;
                team_home->total_loss++;
            }
            // points is equals, choose randomly winner
            else
            {
                int random = rand() % 2;
                if (random == 0)
                {
                    winner = team_home->team_name;
                    team_home->total_win++;
                    team_home->total_points_wins += team_home->team_result;
                    team_outside->total_points_loss += team_outside->team_result;
                    team_outside->total_loss++;
                }
                else
                {
                    winner = team_outside->team_name;
                    team_outside->total_win++;
                    team_outside->total_points_wins += team_outside->team_result;
                    team_home->total_points_loss += team_home->team_result;
                    team_home->total_loss++;
                }
            }
        };
        // operator <<
        friend ostream &operator<<(ostream &os, const Game &game)
        {
            os << "Game: " << game.team_home->team_name << " vs " << game.team_outside->team_name << endl;
            os << "Result: " << game.team_home->team_result << " : " << game.team_outside->team_result << endl;
            os << "check resulat again" << game.team_home->team_result << " : " << game.team_outside->team_result << endl;

            os << "Winner: " << game.winner << endl;
            // os<< "Remainder basket: " << game.remainder_basket << endl;
            os << "total win: " << game.team_home->total_win << " : " << game.team_outside->total_win << endl;
            return os;
        }
    };
};