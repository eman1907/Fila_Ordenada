#include <stdio.h> 
#include <stdlib.h>
 #include "fila.h" 

int main(){ 

	Fila* f = fila_cria(); 
	FILE* arq = fopen("cliente.txt" , "r"); 

	int idade; 
	while(fscanf(arq, "%d" , &idade) != EOF){ 
		fila_insere(f, idade); 
	} fila_ordena(f); 

	while(f != NULL){ 
		printf("%d " , fila_remove(f)); 
	} 

	fclose(arq); 
	fila_libera(f); 

	return 0;
	 }
