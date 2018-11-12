#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//classe processo
class Processo {

public:
    Processo(string nome1, string chegada1, string exec, string prioridade1);
    int getProcessAtribIndex(string atribute);
    string getIndexProcessAtrib(int i);
public:
    int nome;
    int chegada;
    int tempo_exec;
    int prioridade;
    int fila;

};

Processo::Processo(string nome1, string chegada1, string exec, string prioridade1) {
    nome = std::stoi(nome1);
    chegada = std::stoi(chegada1);
    tempo_exec = std::stoi(exec);
    prioridade = std::stoi(prioridade1);
    fila = 1;
}

int Processo::getProcessAtribIndex(string atribute){
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
}

string Processo::getIndexProcessAtrib(int i){

    switch(i){
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
}