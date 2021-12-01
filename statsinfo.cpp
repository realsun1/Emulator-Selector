/***************************************************************************//**
 * @brief storing stats data into a class
 *
 * @authors Junshen Xu
 ******************************************************************************/
#include "statsinfo.h"

using namespace std;
        
        void StatsInfo::setTitle(string input){
            title=input;
        }
        void StatsInfo::settimePlayed(string input){
            time=input;
        }
        void StatsInfo::setnumtime(string input){
            num=input;
        }
        string StatsInfo::getTitle(){
            return title;
        }
        string StatsInfo::getTime(){
            return time;
        }
        string StatsInfo::getNum(){
            return num;
        }
        StatsInfo::StatsInfo(string Title, string Tinput, string Ninput){
            time=Tinput;
            num=Ninput;
            title = Title;
        }
        StatsInfo::StatsInfo(){

        }