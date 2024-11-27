typedef struct fila Fila; 
typedef struct filano FilaNo; 

struct fila{ 
	FilaNo* prim;
	 FilaNo* ult;
	}; 

struct filano{ 
	int idade; 
	FilaNo* prox; 
	FilaNo* ant; 
	}; 

Fila* fila_cria(); 

void fila_insere(Fila* f, int v); 

void fila_ordena(Fila *f); 

int verifica_ordem_certa(Fila *f); 

int verifica_ordem_errada(Fila *f); 

void inverte_fila(Fila* f);

int fila_remove(Fila* f); 

void fila_libera(Fila *f);

