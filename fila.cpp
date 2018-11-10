#include "objects.cpp"
#include <iostream>

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

Fila *destroiFila(Fila *f){
  if(f->percorreFila()) destroiFila(f->percorreFila());
  free(f);
}
