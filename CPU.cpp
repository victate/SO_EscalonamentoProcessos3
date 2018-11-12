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
    char continuar;

    std::list<Processo>::iterator it;

    while(((((((fila_exec.lista_processos.size()>0) || (processo.tempo_exec>0))
              || (fila_aux.lista_processos.size()>0)) || (fila2.lista_processos.size()>0))
            || (fila3.lista_processos.size()>0)) || (fila4.lista_processos.size()>0))){

        if(contador>0){
            cout<<"\n\nContinuar? [S] [N]: ";
            cin>>continuar;
        }

        if((continuar == 's' or continuar=='S') or contador==0){

            if(fila_aux.lista_processos.size()>0){
                if(fila_aux.primeiro().chegada <= contador){
                    if(!fila_exec.has(fila_aux.primeiro())){
                        fila_exec.insereProcesso(fila_aux.primeiro());
                    }
                    it = fila_aux.lista_processos.begin();
                    fila_aux.lista_processos.erase(it);
                }
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

            if(processo.fila==1){
                quantum = fila.quantum;
                it = fila.lista_processos.begin();
                if((*it).nome == processo.nome){
                    fila.lista_processos.erase(it);
                }
            }else{
                if(processo.fila==2){
                    quantum = fila2.quantum;
                    it = fila2.lista_processos.begin();
                    if((*it).nome == processo.nome){
                        fila2.lista_processos.erase(it);
                    }
                }else{
                    if(processo.fila==3){
                        quantum = fila3.quantum;
                        it = fila3.lista_processos.begin();
                        if((*it).nome == processo.nome){
                            fila3.lista_processos.erase(it);
                        }
                    }else{
                        if(processo.fila==4){
                            quantum=fila4.quantum;
                            it = fila4.lista_processos.begin();
                            if((*it).nome == processo.nome){
                                fila4.lista_processos.erase(it);
                            }
                        }else{
                            quantum=1;
                        }
                    }
                }
            }

            if(fila_aux.lista_processos.size()==0) {
                if (fila2.lista_processos.size() > 0) {
                    fila_aux = fila2;
                }else {
                    if (fila3.lista_processos.size() > 0) {
                        fila_aux = fila3;
                    }else{
                        if (fila4.lista_processos.size() > 0) {
                            fila_aux = fila4;
                        }
                    }
                }
            }

            cout<<"\nContador: "<<contador;
            cout<<"     Quantum: "<<quantum;
            cout<<"     Processo: "<<processo.nome;
            cout<<"\n------------------------------------------";
            cout<<"\nFila1: "<<fila.toString();
            cout<<"\nFila2: "<<fila2.toString();
            cout<<"\nFila3: "<<fila3.toString();
            cout<<"\nFila4: "<<fila4.toString();

            contador++;
        }
    }

    cout<<"Encerrado";
    return fila_exec;
}
