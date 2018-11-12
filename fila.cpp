#include <iostream>
#include <vector>
#include <list>
#include "processo.cpp"

class Fila{

public:
    Fila(int id, int quantum);
    void rodaProcesso();
    int insereProcesso(Processo proc);
    void encadeiaFila(Fila *fila);
    Fila *percorreFila();
    void removeProcesso(int i);
    void transfereProcesso(int i);
    Processo primeiro();
    Processo index(int i);
    int quantum;
    int id;
    list<Processo> lista_processos;
};

Fila::Fila(int id1, int quantum1){
    id = id1;
    quantum = quantum1;
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