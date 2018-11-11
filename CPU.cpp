#include "fila.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <pbt.h>

class CPU {

private:
    int contador;
    Fila fila = Fila(0,0);
    Fila fila2 = Fila(0,0);
public:
    CPU(Fila fila, Fila fila2);
    bool iniciaCPU();
};

CPU::CPU(Fila fila1, Fila fila2) {
    contador = 0;
    fila = fila1;
    fila2 = fila2;
    iniciaCPU();
}


bool CPU::iniciaCPU(){

    int quantum = fila.quantum;
    int pos_fila = 0;
    Processo processo = Processo("",0,0,0);
    int inicio = 0;
    Fila fila2 = Fila(1,2);

    do{
        contador++;

        if(processo.nome==""){
            if(fila.index(pos_fila).chegada<=contador){
                processo = fila.index(pos_fila);
                fila.lista_processos.remove(processo);
                inicio = contador;
            }
        }
        else{
            if(contador-inicio >= quantum){
                if(fila.lista_processos.size()>0){
                    fila2.insereProcesso(processo);
                    processo = fila.index(pos_fila);
                    fila.lista_processos.remove(processo);
                }
                inicio=contador;
            }
        }
        if(processo.tempo_exec>0){
            processo.tempo_exec--;
        }
    }
    while(GetKeyState(VK_BACK));
}
