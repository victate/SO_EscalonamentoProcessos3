#include <iostream>
#include <vector>
#include <list>
#include "processo.cpp"

class Fila{

public:
    Fila(int id, int quantum);
    string toString();
    int insereProcesso(Processo proc);
    Processo primeiro();
    bool has(Processo processo);
    Processo index(int i);
    int quantum;
    int id;
    list<Processo> lista_processos;
};

Fila::Fila(int id1, int quantum1){
    id = id1;
    quantum = quantum1;
}

string Fila::toString(){
    int i;
    string result = "";
    std::list<Processo>::iterator it = lista_processos.begin();
    for(i=0; i<lista_processos.size(); i++){
        std::advance(it, i);
        if(i==0){
            result = std::to_string((*it).nome) + "-> Chegada: "+std::to_string((*it).chegada);
        }else{
            result = result + ", " + std::to_string((*it).nome) + "-> Chegada: "+std::to_string((*it).chegada);
        }
    }
    return "["+result+"]";
}

bool Fila::has(Processo processo){
    int i;
    std::list<Processo>::iterator it = lista_processos.begin();
    for(i=0; i<lista_processos.size(); i++){
        if((*(it)).nome == processo.nome){
            return true;
        }
    }
    return false;
}

int Fila::insereProcesso(Processo processo) {
    int i;
    std::list<Processo>::iterator it = lista_processos.begin();
    for(i=0; i<=lista_processos.size(); i++){
        std::advance(it, i);
        if(processo.chegada < (*it).chegada) {
            lista_processos.insert(it, processo);
            return 1;
        }
        if(processo.chegada == (*it).chegada) {
            if(processo.prioridade > (*it).prioridade){
                lista_processos.insert(it, processo);
                return 1;
            }
            else{
                std::advance(it, i+1);
                lista_processos.insert(it, processo);
                return 1;
            }
        }
    }
    lista_processos.insert(lista_processos.end(), processo);
    return 1;

}

Processo Fila::primeiro(){
    std::list<Processo>::iterator it = lista_processos.begin();
    return *it;
}
Processo Fila::index(int i) {
    std::list<Processo>::iterator it = lista_processos.begin();
    std::advance(it, i);
    return *it;
}
Fila *f;
Fila *destroiFila(Fila *f);