#include <iostream>
#include <vector>
#include <list>
#include "processo.cpp"

class Fila{

public:
    Fila(int id, int quantum);
    void rodaProcesso();
    void insereProcesso(Processo proc);
    void encadeiaFila(Fila *fila);
    Fila *percorreFila();
    void removeProcesso(int i);
    void transfereProcesso(int i);
    Processo primeiro();
    Processo index(int i);

private:
    int quantum;
    int id;
    list<Processo> lista_processos;
};

Fila::Fila(int id1, int quantum1){
    id = id1;
    quantum = quantum1;
}

void Fila::insereProcesso(Processo processo) {
    lista_processos.insert(lista_processos.end(),processo);
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