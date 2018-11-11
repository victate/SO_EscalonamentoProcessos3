#include <iostream>
#include <vector>
#include <string>

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

Fila *f;

Fila *criaFila();
Fila *destroiFila(Fila *f);
