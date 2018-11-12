#include "fila.cpp"
#include <stdio.h>
#include <stdlib.h>

class CPU {

private:
    int contador;
public:
    CPU();
    Fila iniciaCPU(Fila fila, Fila fila2, Fila fila3, Fila fila4);
};

CPU::CPU() {
    contador = 0;
}


Fila CPU::iniciaCPU(Fila fila, Fila fila2, Fila fila3, Fila fila4){

    Processo processo = Processo("0", "0", "0", "0");

    int inicio = 0;
    int quantum = 0;
    Fila fila_exec = Fila(0,fila.quantum);
    Fila fila_aux = fila;

    std::list<Processo>::iterator it;

    while(((((((fila_exec.lista_processos.size()>0) || (processo.tempo_exec>0))
              || (fila_aux.lista_processos.size()>0)) || (fila2.lista_processos.size()>0))
            || (fila3.lista_processos.size()>0)) || (fila4.lista_processos.size()>0))){

        printf("\nContador: %d", contador);
        printf(" Processo: %d", processo.nome);

        if(processo.fila==1){
            quantum = fila.quantum;
        }else{
            if(processo.fila==2){
                quantum = fila2.quantum;
            }else{
                if(processo.fila==3){
                    quantum = fila3.quantum;
                }else{
                    if(processo.fila==4){
                        quantum=fila4.quantum;
                    }else{
                        quantum=1;
                    }
                }
            }
        }
        if(fila_aux.lista_processos.size()>0){
            if(fila_aux.primeiro().chegada <= contador){
                fila_exec.insereProcesso(fila_aux.primeiro());
                it = fila_aux.lista_processos.begin();
                fila_aux.lista_processos.erase(it);}
        }

        if(processo.nome==0){
            if(fila_exec.lista_processos.size()>0){
                processo = fila_exec.primeiro();
                it = fila_exec.lista_processos.begin();
                fila_exec.lista_processos.erase(it);
                inicio = contador;
            }
        }
        else{
            if(contador-inicio >= quantum){
                if(processo.tempo_exec>0){
                    if(fila_exec.lista_processos.size()>0){
                        if(processo.fila==1) {
                            processo.fila=2;
                            fila2.insereProcesso(processo);
                        }
                        else{
                            if(processo.fila==2) {
                                processo.fila=3;
                                fila3.insereProcesso(processo);
                            }
                            else{
                                if(processo.fila==3){
                                    processo.fila=4;
                                    fila4.insereProcesso(processo);
                                }
                            }
                        }

                        processo = fila_exec.primeiro();
                        it = fila_exec.lista_processos.begin();
                        fila_exec.lista_processos.erase(it);
                    }
                }
                inicio=contador;
            }
        }
        if(processo.tempo_exec>0){
            processo.tempo_exec--;
        } else {
            if (fila_exec.lista_processos.size() > 0) {
                processo = fila_exec.primeiro();
                it = fila_exec.lista_processos.begin();
                fila_exec.lista_processos.erase(it);
            }
        }

        if(fila_aux.lista_processos.size()==0){
            if(fila2.lista_processos.size()>0){
                fila_aux = fila2;
                it = fila2.lista_processos.begin();
                while(fila2.lista_processos.size()>0){
                    fila2.lista_processos.erase(it);
                }
            }
            else{
                if(fila3.lista_processos.size()>0){
                    fila_aux = fila3;
                    it = fila3.lista_processos.begin();
                    while(fila3.lista_processos.size()>0){
                        fila3.lista_processos.erase(it);
                    }
                }else{
                    if(fila4.lista_processos.size()>0){
                        fila_aux = fila4;
                        it = fila4.lista_processos.begin();
                        while(fila4.lista_processos.size()>0){
                            fila4.lista_processos.erase(it);
                        }
                    }
                }
            }
        }
        contador++;

    }
    return fila_exec;
}
