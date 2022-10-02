#include <iostream>
#include <string>

int converteSensor(float medida,float vi,float vf){
	float valor = 0;
	valor = 100* (medida - vi)/(vf-vi);
	return (int) valor;
}

int leSensor(char *direcao){
	int medida;
	printf("Digite o valor do sensor %s: ",direcao);
	scanf("%i",&medida);
	return medida;	
}
int leComando(){
	char resultado[5];
	printf("Deseja continuar o mapeamento ? (s/n) ");	
	scanf("%s",resultado);
	if(strcmp(resultado,"s")==0){
		return(1);
	}else{
		return(0);
	}
}
int armazenaMedida(int *v,int medida,int posatual,int maxv){
	if(posatual < maxv){
		v[posatual] = medida;
		posatual++;		
		return(posatual);
	}else{
		return(0);
	}
}

char *direcaoMenorCaminho(int *v,int *maiorCaminho){
	int maiorMedida = -1;
	int maiorIndice = -1;
	for(int i=0; i<4; i++){
		if( v[i] > maiorMedida ){
			maiorMedida = v[i];
			maiorIndice = i;			
		}		
	}	
	(*maiorCaminho)  = maiorMedida;
	switch(maiorIndice){
		case 0: return ("Direita");
		case 1: return ("Esquerda");		
		case 2: return ("Frente");
		case 3: return ("Tras");			
	}
	return("Ficar");	
}



int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int posAtualVetor = 0;
	int *vetorMov = v;
	int dirigindo = 1;		
	while(dirigindo){
		int medida = leSensor("direita");
		medida = converteSensor(medida,0,830);
		posAtualVetor = armazenaMedida(vetorMov,medida,posAtualVetor, maxVetor*4);
        /////////////////////////////////////////////
		medida = leSensor("esquerda");
		medida = converteSensor(medida,0,830);
		posAtualVetor = armazenaMedida(vetorMov,medida,posAtualVetor, maxVetor*4);
		/////////////////////////////////////////////
		medida = leSensor("frente");
		medida = converteSensor(medida,0,830);
		posAtualVetor = armazenaMedida(vetorMov,medida,posAtualVetor, maxVetor*4);
		/////////////////////////////////////////////
		medida = leSensor("tras");
		medida = converteSensor(medida,0,830);
		posAtualVetor = armazenaMedida(vetorMov,medida,posAtualVetor, maxVetor*4);

		dirigindo = leComando();		
	}
	return posAtualVetor;
}

void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}


int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}