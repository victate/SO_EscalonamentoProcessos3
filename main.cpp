#include <iostream>
#include <vector>
#include <string>
#include "objects.cpp"
#include "sort_by.cpp"
#include "fila.h"


using namespace std;

int main() {

    Processo *example;
    Processo p;

    int p_len, i;

    cout<<"How many processes, please?\n";
    cin>>p_len;

    example = (Processo*) malloc(p_len*sizeof(Processo));
    cout<< sizeof(Processo);

    for(i=0; i<p_len; i++){
        cout<<"Process no ";
        cin>>p.name;
        cout<<"Process Arrival Time:";
        cin>>p.arrival;
        cout<<"Process Duration:";
        cin>>p.exec_time;
        cout<<"Process IO Start Time:";
        cin>>p.start_IO;
        cout<<"Process IO Duration:";
        cin>>p.duration_IO;
        cout<<"Process Priority:";
        cin>>p.priority;
        example[i] = p;
        cout<<"Name: ";
        cout<<example[i].name;
        cout<<"\nArrival Time: ";
        cout<<example[i].arrival;
        cout<<"\n--------------------\nnext\n--------------------\n";

    }
    if(p_len>0){
        example = sort_by(example, p.getProcessAtribIndex("priority"));
    }

    free(example);
    return 0;
}
