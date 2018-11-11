#include <iostream>
#include <vector>
// #include "objects.cpp"

class Fila{
  public:
    Fila(int quant, int num);
    void rodaProcesso();
    void insereProcesso(Processo proc);
    void encadeiaFila(Fila *fila);
    Fila *percorreFila();
    void removeProcesso(int i);
    void transfereProcesso(int i);
    ~Fila();
  private:
    int quantum;
    int numero;
    vector<Processo> processos;

};

Fila *f;

Fila *criaFila();
Fila *destroiFila(Fila *f);
