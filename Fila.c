#include <stdio.h> 
#include <stdlib.h> 
#include "Fila.h" 

Fila* fila_cria(){ 
	Fila* f = malloc(sizeof(Fila));
	 if (f == NULL) exit(1); 
	 f->prim = NULL; 
	 f->ult = NULL; 
	return f; 
} 


void fila_insere(Fila* f, int v){ 
	FilaNo* n = malloc(sizeof(FilaNo)); 
	if (n == NULL) 	exit(1);
		 n->idade = v; 
		 n->prox = NULL;
		 n->ant = f->ult; 

	if (f->ult != NULL){ 
		f->ult->prox = n; 
	} 
	else f->prim = n;

	 f->ult = n; 

} 

int verifica_ordem_certa(Fila *f){ 
	int ok = 1;
	FilaNo* p = f->prim;
	int x = p->idade;
	for (p; p != NULL; p = p->prox){
		if (x < p->idade){
			ok = 0;
			break;
		}
		x = p->idade; 
	} 
	return ok;
} 

int verifica_ordem_errada(Fila *f){ 
	int ok = 1;
	FilaNo* p = f->prim;
	int x = p->idade;
	for (p; p != NULL; p = p->prox){
		if (x > p->idade){
			ok = 0;
			break;
		}
		x = p->idade; 
	} 
	return ok;
} 

void inverte_fila(Fila* f){
	if (f->prim != NULL && f->prim->prox != NULL){
		
		FilaNo* n = f->prim;
		FilaNo* n2 = NULL;

		while(n != NULL){
			n2 = n->prox;
			n->ant = n->prox;
			n->prox = n2;
			n = n->ant;
		}

		n2 = f->prim;
		f->prim = f->ult;
		f->ult = n2;
	}
}


void fila_ordena(Fila* f){ 
	if (f->prim != NULL && f->prim->prox != NULL){
		int ok = 1;
		while(ok){
			ok = 0;
			FilaNo *n = f->prim;

		while(n->prox != NULL){
				if (n->idade < n->prox->idade){
					int temp = n->idade;
					n->idade = n->prox->idade;
					n->prox->idade = temp;

					ok = 1;
				} 
				n = n->prox;
			} 
		}
	}
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
