/***************************************************************************//**
 * @brief Header file for statsinfo
 *
 * @authors Junshen Xu
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include<string>

using namespace std;

class StatsInfo{

    private:
        string time;
        string num;
        string title;
    public:
        void setTitle(string input);
        void settimePlayed(string input);
        void setnumtime(string input);
        string getTime();
        string getNum();
        string getTitle();

        StatsInfo(string Title,string Tinput,string Ninput);
        StatsInfo();
};