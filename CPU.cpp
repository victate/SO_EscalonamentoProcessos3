#include "fila.cpp"
#include <stdio.h>
#include <stdlib.h>

class CPU {

private:
    int contador;
    Fila fila;
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
    Processo processo;

    while(exec){

        if (contador==0){
            if(fila.primeiro().chegada == contador){
                processo = fila.primeiro();
            }
            else{
                contador++;
            }
        }

        else{
            contador++;
            processo.tempo_exec--;

            if(contador-inicio == quantum){

                if(fila.index(pos_fila+1).chegada<=quantum){
                    printf("----");
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
        pos_fila++;
    }
}
