#include <stdio.h> 
#include <stdlib.h>
#include "Fila.h" 

int main(){  

	Fila* f = fila_cria(); 

	FILE* arq_entrada = fopen("Cliente.txt" , "w"); //cria uma arquivo de escrita 
	if (arq_entrada == NULL){			
		printf("Erro ao abrir arquivo\n");
		return 1;
	} 

	printf("Digite a idade dos indivíduos presentes na fila e 0 para finalizar:\n");
	int id;
	/* lê as idades fornecidas pelo usuário e adiciona ao arquivo aberto na ordem que aparecem
	e ultiliza 0 como critério de parada */
	while(scanf("%d" , &id), id != 0){ 		
		fprintf(arq_entrada, "%d\n" , id);  	
	} 						

	fclose(arq_entrada); //fecha o arquivo de escrita 

	FILE* arq = fopen("Cliente.txt" , "r"); //abre o arquivo anterior para leitura

	int idade; 
	//lê as idades presentes no arquivo e adicona na fila duplamente encadeada
	while(fscanf(arq, "%d" , &idade) != EOF){ 
		fila_insere(f, idade); 
	}
	
	if (!verifica_ordem_certa(f) && !verifica_ordem_errada(f)) {fila_ordena(f);} 
	else if (verifica_ordem_errada(f)) {inverte_fila(f);} 

	//imprime a fila disposta na ordem correta após análise 
	printf("A ordem do atendimento será:\n");
	while(f != NULL){ 
		printf("%d " , fila_remove(f)); 
	} 

	fclose(arq); //fecha o arquivo de leitura 
	
	fila_libera(f); 

	return 0;
 } 
