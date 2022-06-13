#include <iostream>
#include <string>
#include "doctest.h"
using namespace std;

#include "Team.hpp"
#include "Leauge.hpp"
#include "Game.hpp"
using namespace b_ball;

TEST_CASE("Test Leauge")
{
    Leauge leauge;
    CHECK_NOTHROW(cout << leauge << endl);
    CHECK_NOTHROW(leauge.show_Statistics());
    CHECK(leauge.teams_Leauge.size() == 20);
    CHECK_THROWS(leauge.teams_Leauge.at(21));
    CHECK_NE(leauge.teams_Leauge.at(0)->team_name, "");
    CHECK_EQ(leauge.schedule->games.size(), 380);
    Game* check= leauge.schedule->games.at(0);
    CHECK_NOTHROW(cout<< *check << endl);
    string winner= check->winner;
    CHECK_NE(winner, "ALBI");
    CHECK_NOTHROW(leauge.schedule->games.at(20)->is_winner());
    Game* check1= leauge.schedule->games.at(1); 
    string home_team= check1->team_home->team_name;
    int res= check1->team_home->team_result;
    CHECK_NE(res, 0);
    int wins=  check1->team_home->total_win;
    CHECK_NE(wins, 0);
    CHECK_NE(home_team, "ECHO");
    CHECK_NE(leauge.schedule->games.size(), 400);
    CHECK_THROWS(leauge.schedule->games.at(381));
    CHECK_NOTHROW(leauge.schedule->games.at(50));
    CHECK_NE(leauge.teams_Leauge.at(3)->team_name,"TALNET");
    int result= leauge.teams_Leauge.at(3)->team_result;
    CHECK_NE(result, 0);
    CHECK_THROWS(leauge.schedule->games.at(381)->is_winner());
    CHECK_NOTHROW(leauge.schedule->games.at(50)->start_game());
    CHECK_NOTHROW(leauge.schedule->games.at(50)->is_winner());
    

}