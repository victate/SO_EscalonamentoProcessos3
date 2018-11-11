#include "fila.h"
#include <iostream>

//métodos da classe fila

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

Fila::transfereProcesso(){
  if(prox->next){
    prox->insereProcesso(processos[i]);
    processos.erase(0);
  }
  else{ //processos voltam pra primeira fila? Senão apaga essa parte
    f->insereProcesso(processos[i]); //processo volta pro início
    processos.erase(0);
  }
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

//funcoes da estrutura

Fila *criaFila(){
  Fila *prim = NULL;
  Fila temp;
  for(int i = 0; i<4;i++){
    if(!prim) prim = Fila(8, 4);
    else{
      switch(i){
        case 1:
          temp = Fila(4, 3);
        case 2:
          temp = Fila(2, 2);
        case 3:
          temp = Fila(1, 1);
      }
      temp.encadeiaFila(prim);
      prim = temp;
    }
  }
  return prim;
}

void destroiFila(Fila *f){
  if(f->percorreFila()) destroiFila(f->percorreFila());
  free(f);
}
