
#include "statsinfo.h"

using namespace std;
        
        void StatsInfo::settimePlayed(string input){
            time=input;
        }
        void StatsInfo::setHighestScore(string input){
            score=input;
        }

        string StatsInfo::getTime(){
            return time;
        }
        string StatsInfo::getScore(){
            return score;
        }
        StatsInfo::StatsInfo(string Tinput, string Sinput){
            time=Tinput;
            score=Sinput;
        }
        StatsInfo::StatsInfo(){

        }