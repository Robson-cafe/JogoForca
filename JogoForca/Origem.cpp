#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

//---------------------------------------------------------------

void limpaTela() {
  system("CLS");
}

//---------------------------------------------------------------

string palavraAleatoria() {
  string palavras[3] = { "abacaxi", "uva", "laranja" };

  int indiceAleatorio = rand() % 3;
  //cout << palavras[indiceAleatorio];
  return palavras[indiceAleatorio];
}

//---------------------------------------------------------------

string criaMascaraPalavra(
  string palavra,
  int tamanhoPalavra
) 
{
  string mascaraPalavra;
  for (int i = 0; i < tamanhoPalavra; i++) {
    mascaraPalavra += "_";
  }
  return mascaraPalavra;
}
//---------------------------------------------------------------

void exibeStatus(
  string mascaraPalavra,
  int tamanhoPalavra,
  int tentaivasRestantes,
  string letraJaArricada,
  string mensagem
)
{
  cout << mensagem << "\n";
  cout << "Palavra:" << mascaraPalavra << " (Tamanho: " << tamanhoPalavra << ")";
  cout << "\n\nTentaivas retantes:" << tentaivasRestantes;


  cout << "\nLetras arriscadas:";
  for (unsigned int i = 0; i < letraJaArricada.size(); i++) {
    cout << letraJaArricada[i] << ", ";
  }
}
//---------------------------------------------------------------

int jogar(int numJogador) 
{
  string palavra;

  if (numJogador == 1) {
    palavra = palavraAleatoria();
  }
  else {
    limpaTela();
    cout << "Digite uma palavra: ";
    cin >> palavra;
  }
  int tamanhoPalavra = palavra.size();

  string mascaraPalavra = criaMascaraPalavra(palavra, tamanhoPalavra);
  
  int tentativas = 0;
  int opcao = 0;
  const int maximoTentativas = tamanhoPalavra + 3;
  int tentaivasRestantes = maximoTentativas - tentativas;

  char letra;
  string letraJaArricada;
  string mensagem = "Bem vindo a forca!!\n";
  bool jaDigitou = false;
  bool acertouLetra = false;

  bool ehPalavraDiferente = palavra != mascaraPalavra;

  while (ehPalavraDiferente && maximoTentativas - tentativas > 0) {
    limpaTela();
    if (palavra == mascaraPalavra) {
      break;
    }

    exibeStatus(mascaraPalavra, tamanhoPalavra, maximoTentativas - tentativas, letraJaArricada, mensagem);

    cout << "\nDigite uma letra: ";
    cin >> letra;

    for (int j = 0; j < tentativas; j++) {
      if (letraJaArricada[j] == letra) {
        mensagem = "Essa letra já foi digitada!!!\n";
        jaDigitou = true;
      }
    }

    if (jaDigitou == false) {
      letraJaArricada += tolower(letra);

      for (int i = 0; i < tamanhoPalavra; i++) {
        if (palavra[i] == tolower(letra)) {

          mascaraPalavra[i] = palavra[i];

          
          acertouLetra = true;
        }
      }

      if (acertouLetra == false) {
        mensagem = "Você errou uma letra!!!\n";
      }
      else {
        mensagem = "Você acertou uma letra!!!\n"; 
      }

      tentativas++;
    }
    acertouLetra = false;
    jaDigitou = false;
  }

  if (palavra == mascaraPalavra) {
    limpaTela();
    cout << "Parabéns você venceu!!!\n";

    cout << "\n  xxxxxxxxxxxxx";
    cout << "\n  x  Campeão  x";
    cout << "\n  xxxxxxxxxxxxx";
    cout << "\n       xxx     ";
    cout << "\n       xxx     ";
    cout << "\n       xxx     ";
    cout << "\n     xxxxxxx   ";
    
    cout << "\n\nDeseja reiniciar:";
    cout << "\n1 - Sim";
    cout << "\n2 - Não";
    cout << "\nEscolha uma opção e tecle ENTER: ";
    cin >> opcao;
    return opcao;

  }
  else {
    limpaTela();
    cout << "Você perdeu mané!!!\n";

    cout << "\n  xxaxxxxxxxxxx";
    cout << "\n  x  Boommm!  x";
    cout << "\n  xxxxxxxxxxxxx";

    cout << "\n\nDeseja reiniciar:";
    cout << "\n1 - Sim";
    cout << "\n2 - Não";
    cout << "\nEscolha uma opção e tecle ENTER: ";
    cin >> opcao;
    return opcao;
  }

  //cout << "A palavra secreta é:" << palavra << " (Tamanho: " << tamanhoPalavra << ")";
  //cout << "\nMascara:" << mascaraPalavra;
}

//---------------------------------------------------------------

void menuInicial() {
  int opcao = 0;

  while (opcao < 1 || opcao > 3) {
    limpaTela();
    cout << "Bem Vindo ao Jogo";
    cout << "\n1 - Jogar sozinho";
    cout << "\n2 - Jogar em dupla";
    cout << "\n3 - Sobre";
    cout << "\n4 - Sair";
    cout << "\nEscolha uma opção e tecle ENTER: ";
    cin >> opcao;

    switch (opcao) {
    case 1:
      if (jogar(1) == 1) {
        menuInicial();
      }
      break;

    case 2:
      if (jogar(2) == 1) {
        menuInicial();
      }
      break;

    case 3:
      cout << "Informações do Jogo";
      limpaTela();
      cout << "Jogo da Forca - Desnvolvimento by Café - 2022";
      cout << "\n1 - Voltar";
      cout << "\n2 - Sair";
      cout << "\nEscolha uma opção e tecle ENTER: ";
      cin >> opcao;
      if (opcao == 1) {
        menuInicial();
      }
      break;

    case 4:
      cout << "Até mais";
      break;
    }
  }
}

//---------------------------------------------------------------

int main() {
  setlocale(LC_ALL, "Portuguese");

  srand((unsigned) time (NULL));

  menuInicial();

  return 0;
}
