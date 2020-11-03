#include <stdio.h>
#include "funcoesB.c"
#define TAM 100

/*Definimos o tamanho padrão do vetor por dificuldades no uso do malloc */


int main(void){
	FILE *arq;
	Covid vet[TAM];
	int i, d, m, y, S=0;
	float total;
	
	arq = fopen("covid19.txt", "r");

    for (i = 0; !feof(arq); i++){
        fscanf(arq, "%d %d %d %lf \n",
               &vet[i].day,
               &vet[i].month,
               &vet[i].year,
               &vet[i].index);
        vet[i].date = vet[i].year*365 + vet[i].month*32 + vet[i].day;
        S++;
        //printf("%lf\n", vet[i].date); //váriavel criada para auxiliar na ordenação dos dados por data
	};
	
	/*printf("Dados antes da ordenacao:\n");
	for(i=0;i<S;i++){
		printf("%d %d %d %lf\n",
			vet[i].day,
            vet[i].month,
            vet[i].year,
            vet[i].index);
	};*/
	
	quickSort(S, &vet, 0, S-1);
	
	printf("\nDados depois da ordenacao:\n Dia-Mes-Ano-Indice\n");
	for(i=0;i<S;i++){
		printf(" %d - %d - %d - %.2lf\n",
			vet[i].day,
            vet[i].month,
            vet[i].year,
            vet[i].index);
	};

	GraphSection(&vet, S);
	
	printf("\n\nDigite a data(DD MM AAAA) que deseja pesquisar: ");
    scanf("%d %d %d", &d, &m, &y);
    total = LinearSearch(d, m, y, &vet, S-1);
    if(total == -1)
    	printf("Nao ha indices para a data requisitada!");
    else
    	printf("O indice refenente a data %d/%d/%d foi de %.1f", d, m, y, total);
    
	return(0);
}
