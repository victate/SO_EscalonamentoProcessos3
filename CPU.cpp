#include "processo.cpp"
#include <stdio.h>
#include <stdlib.h>

class CPU{

private:
        int contador;
        Processo processo;
        Processo * fila;
public:
    CPU(Processo *fila)
        : contador(0), fila(fila), processo()
    {iniciaCPU();}

    bool iniciaCPU(){
        bool exec = true;
        int quantum = 1;
        int inicio = contador;
        int pos_fila = 0;
        while(exec){
            printf("%d\n",contador);
            contador++;
            processo.exec_time--;

            if(contador-inicio == quantum){

                if(fila[pos_fila+1].arrival<=quantum){
                    printf("----");
                    pos_fila++;
                    processo=fila[pos_fila];
                }
                else{
                    if(processo.exec_time<=0 and fila->getProcessAtribIndex()){
                        exec=false;
                    }
                }
                if(processo.exec_time>0){
                    //manda para a próxima fila
                }
                inicio=contador;
            }
        }
    }
};
