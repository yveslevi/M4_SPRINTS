#include <iostream>

using namespace std;
int maxmin()
{
    int i;
    int j;
    int n;
    printf("Digite um numero minimo:\n");
    cin >> n;
    printf("Digite um numero maximo: \n");
    cin >> j;
    printf("Digite um numero: \n");
    cin >> i;
    double distancia ;
    distancia = j - n;
    double ajmed ;
    ajmed = (i/distancia)*100;
    cout << "A media ajustada percentualmente eh " << ajmed << "% \n";
    return 0;
}

int exerciciodois(){
    char d;
    printf("Digite algo: \n ");
    cin >> d;
    cout << d;
    return 0;
}

int exerciciotres(){

}

int exercicioquatro(){

char* dirMaiorDist(int Vetor[]){
  char* direcao[4] = {"Direita", "Esquerda", "Frente", "Tras"};
  int index = 0;
  int maiorValor = 0;
  for(int i = 0; i < 4; i++){
    if(Vetor[i] > maiorValor){
      maiorValor = Vetor[i];
      index = i;
    }
  }
  return direcao[index];
}

int maiorDist(int Vetor[]){
  int index = 0;
  int maiorValor = 0;
  for(int i = 0; i < 4; i++){
    if(Vetor[i] > maiorValor){
      maiorValor = Vetor[i];
      index = i;
    }
  }
  return maiorValor;
}
return 0;
}



int main()
{
    maxmin();
    exerciciodois();
    exercicioquatro();
    return 0;
}



