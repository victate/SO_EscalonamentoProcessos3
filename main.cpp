#include <fstream>
#include <iostream>
#include "CPU.cpp"


using namespace std;

// Executada quando a main começa a rodar, lê o arquivo texto, cria os processos e preenche
// a fila de entrada
int lerArquivo(string nomeArq, Fila fila) {

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
    fila.insereProcesso(item);
  }

  std::cout << "Arquivos lidos!" << '\n';
}

int main() {
  Fila fila = Fila(1,1);
  Fila fila2 = Fila(1,2);
  Fila fila3 = Fila(1,4);
  Fila fila4 = Fila(1,8);

  // começa lendo os processos do arquivo
  std::string nomeArq;
  std::cout << "Olá, bem-vinda ao nosso gerenciador de processos! :)" << '\n';
  std::cout << "Digite o nome do arquivo  ser lido:" << '\n';
  std::cin >> nomeArq;
  std::cout << "Estamos lendo os processos do arquivo..." << '\n';

  lerArquivo(nomeArq, fila);

  CPU nova = CPU(fila);

}
