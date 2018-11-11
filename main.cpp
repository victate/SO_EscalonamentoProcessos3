#include <fstream>
#include <iostream>
#include "objects.cpp"
// #include "sort_by.cpp"
#include "fila.h"


using namespace std;

// Executada quando a main começa a rodar, lê o arquivo texto, cria os processos e preenche
// a fila de entrada
int lerArquivo(string nomeArq) {
  std::ifstream arq(nomeArq);
  if (!arq) {
    std::cout << "Arquivo não encontrado" << '\n';
    return 0;
  }
  // lê as linhas do arquivo uma por vez e cria os processos com os dados
  std::string linha;

  while (std::getline(arq, linha)) {

    //separa cada linha nas 4 "palavras" que a compõe e cria o prcesso
    std::string palavras [4];
    for (int i = 0; i < 4; i++) {
      int fimPalavra = linha.find(";");
      std::string palavra = linha.substr(0, fimPalavra);
      palavras[i] = palavra;
      linha = linha.substr(fimPalavra+1);
    }
    Processo item = Processo(palavras[0], palavras[1], palavras[2], palavras[3]);
  }


  std::cout << "Arquivos lidos!" << '\n';
}

int main() {
  // começa lendo os processos do arquivo
  std::string nomeArq;
  std::cout << "Olá, bem-vinda ao nosso gerenciador de processos! :)" << '\n';
  std::cout << "Digite o nome do arquivo  ser lido:" << '\n';
  std::cin >> nomeArq;
  std::cout << "Estamos lendo os processos do arquivo..." << '\n';

  lerArquivo(nomeArq);

    //
    // Processo *example;
    // Processo p;
    //
    // int p_len, i;
    //
    // cout<<"How many processes, please?\n";
    // cin>>p_len;
    //
    // example = (Processo*) malloc(p_len*sizeof(Processo));
    // cout<< sizeof(Processo);
    //
    // for(i=0; i<p_len; i++){
    //     cout<<"Process no ";
    //     cin>>p.name;
    //     cout<<"Process Arrival Time:";
    //     cin>>p.arrival;
    //     cout<<"Process Duration:";
    //     cin>>p.exec_time;
    //     cout<<"Process IO Start Time:";
    //     cin>>p.start_IO;
    //     cout<<"Process IO Duration:";
    //     cin>>p.duration_IO;
    //     cout<<"Process Priority:";
    //     cin>>p.priority;
    //     example[i] = p;
    //     cout<<"Name: ";
    //     cout<<example[i].name;
    //     cout<<"\nArrival Time: ";
    //     cout<<example[i].arrival;
    //     cout<<"\n--------------------\nnext\n--------------------\n";
    //
    // }
    // if(p_len>0){
    //     example = sort_by(example, getProcessAtribIndex("priority"));
    // }
    //
    // free(example);
    // return 0;
}
