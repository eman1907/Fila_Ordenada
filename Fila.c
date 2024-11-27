#include <stdio.h> 
#include <stdlib.h> 
#include "fila.h" 

Fila* fila_cria(){ 
	Fila* f = malloc(sizeof(Fila));
	 if (f == NULL) exit(1); 
	 f->prim = NULL; 
	 f->ult = NULL; 
	return f; 
} 


void fila_insere(Fila* f, int v){ 
	FilaNo* n = malloc(sizeof(FilaNo)); 
	if (n == NULL) 
		exit(1);
		 n->idade = v; 
		 n->prox = NULL;
		  n->ant = f->ult; 

	if (f->ult != NULL){ 
		f->ult->prox = n; 
	} 
	else f->prim = n;

	 f->ult = n; 

} 


void fila_ordena(Fila* f){ 
	(...) 
} 


int fila_remove(Fila* f){ 
	 if (f->prim == NULL){ 
		exit(1); 
	} 

	FilaNo* n = f->prim; 
	int i = n->idade; 
	f->prim = n->prox; 

	if (f->prim != NULL){ 
		f->prim->ant = NULL; 
	} 
	else f->ult = NULL; 
	
	free(n); 
	return i; 
} 



void fila_libera(Fila *f){ 
	FilaNo* n = f->prim; 
	FilaNo* p = NULL; 
	while(n != NULL){ 
		p = n; 
		n = n->prox; 
		free(p);
	}
	free(f);
}
