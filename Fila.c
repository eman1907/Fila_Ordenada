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
	n->ant = f->ult; 
	n->prox = NULL;

	if (f->ult) f->ult->prox = n;  
	else f->prim = n;

	 f->ult = n; 
}  

int verifica_ordem_certa(Fila *f){ 
	int ok = 1;
	FilaNo* p = f->prim;
	for (p; p->prox != NULL; p = p->prox){
		if (p->idade < p->prox->idade){
			ok = 0;
			break;
		}
	} 
	return ok;
} 

int verifica_ordem_errada(Fila *f){ 
	int ok = 1;
	FilaNo* p = f->prim;
	for (p; p->prox != NULL; p = p->prox){
		if (p->idade > p->prox->idade){
			ok = 0;
			break;
		}
	} 
	return ok;
} 

void inverte_fila(Fila* f){
	if (f->prim != NULL && f->prim->prox != NULL){
		
		FilaNo* n = f->prim;
		FilaNo* n2 = NULL;

		while(n != NULL){
			n2 = n->ant;
			n->ant = n->prox;
			n->prox = n2;
			n = n->ant;
		}

		n2 = f->prim;
		f->prim = f->ult;
		f->ult = n2;
	}
}

void troca_nos(Fila* f, FilaNo* a, FilaNo* b){
	if(a->ant != NULL) a->ant->prox = b;
	else f->prim = b;

	if(b->prox != NULL) b->prox->ant = a;
	else f->ult = a;

	a->prox = b->prox;
	b->ant = a->ant;

	a->ant = b;
	b->prox = a;
}


void fila_ordena(Fila* f){ 
	if (f->prim != NULL){

		int trocou;
		do{
			trocou = 0;
			FilaNo* n = f->prim;

			while(n != NULL && n->prox != NULL){
				if (n->idade < n->prox->idade){ 
					troca_nos(f, n, n->prox);
					trocou = 1;
				}
				else n = n->prox;
			}
		}
		while(trocou); 
	} 
} 


int fila_remove(Fila* f){ 
	 if (f->prim == NULL){ 
		exit(1); 
	} 

	FilaNo* n = f->prim; 
	int i = n->idade; 
	f->prim = n->prox; 

	if (f->prim) f->prim->ant = NULL; 
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
