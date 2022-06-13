// #include <iostream>
// #include <vector>
// using namespace std;

// #include "Schedule.hpp"

// namespace b_ball
// {

//     Schedule::Schedule(vector<Team *> teams_Leauge)
//     {
//         for (size_t i = 0; i < teams_Leauge.size(); i++)
//         {
//             for (size_t j = i + 1; j < teams_Leauge.size(); j++)
//             {
//                 games.push_back(new Game(teams_Leauge[i], teams_Leauge[j]));
//                 games.push_back(new Game(teams_Leauge[j], teams_Leauge[i]));
//             }
//         }
//     };

//     ostream& b_ball::operator<<(ostream &os, const Schedule &schedule)
//     {
//         for (size_t i = 0; i < schedule.games.size(); i++)
//         {
//             os << *schedule.games[i] << endl;
//         }
//         return os;
//     }

//     void Schedule::show_Statistic()
//     {
//     }
// }