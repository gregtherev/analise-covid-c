#include <stdio.h>
#include "cabecalho.h"


/*Fun��o que encontra o menor valor do gr�fico, e partir disso analisa se sua recupera��o foi ou n�o em 'V'. O crescimento em 'V' se da pelo fator do �ndice voltar a ser o que era no
�ltimo per�odo antes de come�ar a queda (com margem de -1%) na mesmo intervalo de tempo em que chegou ao ponto mais baixo com uma folga de 1 per�odo. */
/*Um gr�fico que come�a a cair a partir do �ndice 70% levaria N per�odos para atingir o ponto mais baixo. A partir do ponto mais baixo ele ter� N per�odos
 para atingir os 70% novamente. No caso da nossa fun��o, demos uma margem de 1% de erro, assim caso o gr�fico retorne para 69% ainda ser� considerado. */
void GraphSection(Covid *v, int N){
	int y, i;
	double x= v[0].index;
	for(i=0;i<N;i++){ //achando a posi��o do ponto mais baixo
		if(v[i].index <= x){
			y = i;
			x = v[i].index;
		}		
	}
	i = y; //posi��o do ponto mais baixo
	y *=2; //posi��o m�xima do crescimento

	if(v[y].index+1 >= v[i-(y/2)].index){ //checando se a posi��o m�xima do crescimento(+1%) � maior ou igual que o ponto de �nicio da queda.
		printf("\nO grafico apresenta recuperacao em 'V'!\n");
	}else{
		printf("\nNao apresenta recuperacao em 'V'!\n");
	}
	printf(" Ponto mais alto antes da queda: %.1lf \n Ponto mais baixo do grafico: %.1lf \n Qtd de periodos: %d \n Indice apos os periodos: %.1lf + 1%%", v[i-(y/2)].index, v[i].index, y/2, v[y].index);
}


//Pesquisa linear para buscar o indice referente a data desejada
float LinearSearch(int d, int m, int y, Covid *v, int N) {
	int i;
	for(i=0;i<N;i++){
		if(v[i].year == y){
			if(v[i].month == m){
				if(v[i].day == d){
					return v[i].index;	
				}
			}
			
		}
	}
	return -1;
}

//Quicksort usando uma v�riavel date para ordenar os dados por ordem crescente
float quickSort(int n, Covid *vetor, int esquerda, int direita){
	int i, j, pivo;
	double aux;
	pivo = vetor[direita].date;
	i = esquerda;
	j = direita;
	
	while(i <= j){
		while((vetor[i].date < pivo) && (i < direita)){
			i++;
		}	
		while((vetor[j].date > pivo) && (j > esquerda)){
			j--;
		}
		if(i <= j){
			aux = vetor[i].month;
			vetor[i].month = vetor[j].month;
			vetor[j].month = aux;
			
			aux = vetor[i].day;
			vetor[i].day = vetor[j].day;
			vetor[j].day = aux;
			
			aux = vetor[i].year;
			vetor[i].year = vetor[j].year;
			vetor[j].year = aux;
			
			aux = vetor[i].index;
			vetor[i].index = vetor[j].index;
			vetor[j].index = aux;
			
			aux = vetor[i].date;
			vetor[i].date = vetor[j].date;
			vetor[j].date = aux;
			
			i++;
			j--;	
		}
	}
	if(j > esquerda){
		quickSort(n, vetor, esquerda, j);
	}
	if(i < direita){
		quickSort(n, vetor, i, direita);
	}
};		 

