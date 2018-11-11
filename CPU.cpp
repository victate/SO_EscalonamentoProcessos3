#include "fila.cpp"
#include <stdio.h>
#include <stdlib.h>

class CPU {

private:
    int contador;
    Fila fila = Fila(0,0);
public:
    CPU(Fila fila);
    bool iniciaCPU();
};

CPU::CPU(Fila fila1) {
    contador = 0;
    fila = fila1;
    iniciaCPU();
}


bool CPU::iniciaCPU(){
    bool exec = true;
    int quantum = 1;
    int inicio = contador;
    int pos_fila = 0;
    Processo processo = fila.primeiro();

    while(exec){

        if (processo.chegada<=contador){
            inicio = contador;
            processo.tempo_exec--;

            if(contador-inicio >= quantum){

                if(fila.index(pos_fila+1).chegada<=quantum){
                    pos_fila++;
                    processo=fila.index(pos_fila);
                }
                else{
                    if(processo.tempo_exec<=0){
                        exec=false;
                    }
                }
                if(processo.tempo_exec>0){
                    //manda para a próxima fila
                }
                inicio=contador;
            }
        }
        contador++;
    }
}
