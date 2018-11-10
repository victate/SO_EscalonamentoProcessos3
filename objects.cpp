//
// Created by victa on 09/11/2018.
//
#include <string>
#include <vector>
using namespace std;

//classe processo
class Processo {

  public:
    int getProcessAtribIndex(string atribute);
    string getIndexProcessAtrib(int i);
  private:
        char name;
        int arrival;
        int exec_time;
        int start_IO;
        int duration_IO;
        int priority;

};

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

        case 0:
            return "name";
        case 1:
            return "arrival";
        case 2:
            return "exec_time";
            switch (i){
        case 3:
            return "start_IO";
        case 4:
            return "duracao_IO";
        case 5:
            return "priority";
    }
}

//classe fila

class Fila{
  public:
    Fila(int quant, int num);
    rodaProcesso();
    insereProcesso(Processo proc);
    encadeiaFila(Fila *fila);
    Fila *percorreFila();
    removeProcesso(int i);
    transfereProcesso(int i);
    ~Fila();
  private:
    int quantum;
    int numero;
    vector<Processo> processos;

}

Fila::Fila(int quant, int num){
  quantum = quant;
  numero = num;
  prox = NULL;
}

Fila::insereProcesso(Processo proc){
  vector.push_back(proc);
}

Fila::removeProcesso(int i){
  vector.erase(i);
}

Fila::rodaProcesso(){

}

Fila::transfereProcesso(int i){
  prox->processos.push_back(this->processos[i]);
  this->processos.erase(i);
}

Fila::encadeiaFila(Fila *fila){
  prox = fila;
}

Fila::percorreFila(){
  return prox;
}

Fila::~Fila(){
  cout << "Fim da fila %d" << numero;
}
