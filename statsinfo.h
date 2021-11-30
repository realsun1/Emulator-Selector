#include <iostream>
#include <fstream>
#include<string>

using namespace std;

class StatsInfo{

    private:
        string time;
        string score;
    
    public:
        void settimePlayed(string input);
        void setHighestScore(string input);
        string getTime();
        string getScore();

        StatsInfo(string Tinput,string Sinput);
        StatsInfo();
};