typedef struct fila Fila; 
typedef struct filano FilaNo; 

struct fila{ 
	FilaNo* prim; //ponteiro para o primeiro elemento da fila
	 FilaNo* ult; //ponteiro para o último elemento da fila
	}; 

struct filano{ 
	int idade; //idade de cada indivíduo presente na fila
	FilaNo* prox; //ponteiro para o próximo elemento presente na fila (caso seja o último aponta para NULL)
	FilaNo* ant; //ponteiro para o elemento anterior presente na fila, característica de
	}; 	     //filas duplamente encadeadas (caso seja o primeiro aponta para NULL) 

Fila* fila_cria(); 
//cria uma fila duplamente encadeada apontando prim e ult para NULL

void fila_insere(Fila* f, int v); 
/*insere cada idade digitada pelo usuário dentro da fila na ordem em que aparece,
onde é criado um ponteiro para FilaNo que receberá a idade que foi passada como parametro
e será apontada por ult caso não seja o primeiro elemento da lista, em caso de ser o primeiro 
elemento tanto prim quanto ult irão apontar para a idade escolhida */

void fila_ordena(Fila *f); 
/* funçao será chamada caso "verifica_ordem_certa" e "verifica_ordem_errada" retornem 0 o que 
significa que a lista não segue uma ordem linear nem crescente nem decrescente, o que evidencia
que será necessária a ultilização da função que possui o bubble sort que compara todas idades e 
as ordena da maior para a menor */

int verifica_ordem_certa(Fila *f); 
/* retorna 1 caso as idades já se encontrem dispostas da maior para a menor a fim
de evitar o trabalho da função "fila_ordena" */

int verifica_ordem_errada(Fila *f); 
/* retorna 1 caso as idades já se encontrem dispostas da menor para a maior a fim
de evitar o trabalho da função "fila_ordena", e nesse caso será chamada a função 
"inverte_fila" que será explicada a seguir */

void inverte_fila(Fila* f);
/* é chamada caso "verifica_ordem_errada" retorne 1 e tem por funçao inverter completamente
os elementos presentes na lista para que fiquem dispostos do maior para o menor, fazendo com que
os ponteiros ant e prox de cada elemnto troquem de posição e ao fim da funçaõ também troca os 
ponteiros prim e ult de posição fazendo com que a lista mude a ordem estabelecida anteriormente */ 

int fila_remove(Fila* f); 
/* remove o primeiro elemento da lista agora disposta na ordem correta, imprime dentro da Main e
repete o processo até que a fila esteja vazia a fim de apresentar a ordem de atendimento 
dentre as idades escolhidas */

void fila_libera(Fila *f);
// libera o espaço alocado da fila ultilizada no programa 

