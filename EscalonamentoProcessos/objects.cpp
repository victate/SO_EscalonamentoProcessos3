//
// Created by victa on 09/11/2018.
//
#include <string>
using namespace std;

class Process {

    public:
        char name;
        int arrival;
        int exec_time;
        int start_IO;
        int duration_IO;
        int priority;
};

int getProcessAtribIndex(string atribute){
    if(atribute=="name"){
        return 0;
    }
    if(atribute=="arrival"){
        return 1;
    }
    if(atribute=="exec_time"){
        return 2;
    }
    if(atribute=="start_IO"){
        return 3;
    }
    if(atribute=="duracao_IO"){
        return 4;
    }
    if(atribute=="priority"){
        return 5;
    }
    else{
        return NULL;
    }
}

string getIndexProcessAtrib(int i){
    try {
        switch (i){
            case 0:
                return "name";
            case 1:
                return "arrival";
            case 2:
                return "exec_time";
            case 3:
                return "start_IO";
            case 4:
                return "duracao_IO";
            case 5:
                return "priority";
        }
    }catch(int e){
        return NULL;
    }


}