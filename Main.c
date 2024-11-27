#include <stdio.h> 
#include <stdlib.h>
#include "Fila.h" 

int main(){  

	Fila* f = fila_cria(); 

	FILE* arq_entrada = fopen("Cliente.txt" , "w");
	if (arq_entrada == NULL){
		printf("Erro ao abrir arquivo\n");
		return 1;
	} 


	int id;
	while(scanf("%d" , &id), id != 0){ 
		fprintf(arq_entrada, "%d\n" , id);  
	} 

	fclose(arq_entrada); 

	FILE* arq = fopen("Cliente.txt" , "r"); 

	int idade; 
	while(fscanf(arq, "%d" , &idade) != EOF){ 
		fila_insere(f, idade); 
	}
	
	if (!verifica_ordem_certa(f) && !verifica_ordem_errada(f)) {fila_ordena(f);} 
	else if (verifica_ordem_errada(f)) {inverte_fila(f);} 
	

	while(f != NULL){ 
		printf("%d " , fila_remove(f)); 
	} 

	fclose(arq); 
	
	fila_libera(f); 

	return 0;
 } 
