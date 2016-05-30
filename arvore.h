#include <stdio.h>
#include <stdlib.h>
#include <String.h>
typedef struct no1 No1;
struct no1{
	int dado;
	No1 *esquerda;
	No1 *direita;
};
//--------------MENOR----------------------------
No1* Menor(No1 *pNo){
	while(pNo->esquerda != NULL) {
		pNo = pNo->esquerda;
	}
	return pNo;
}
//------------------PENULTIMO--------------------
No1* penultimoNo(No1 *pNo) {
	No1 *pai;
	if (pNo->direita == NULL) return pNo;
	while(pNo->direita != NULL){
		if (pNo->direita == NULL) break;
		pai = pNo;
		pNo = pNo->direita;
	}
	return pai;
}
//------------------MAIOR------------------------
No1* Maior(No1 *pNo) {
	if (pNo->direita == NULL) return pNo;
	while(pNo->direita != NULL){
		if (pNo->direita == NULL) break;
		pNo = pNo->direita;
	}
	return pNo;
}

//--------------------VERIFICA-VAZIO-------------------------------
int vazia(No1* empty){
	return empty==NULL;
}

//-------------------------IMPRIME--------------------------------
void imprime(No1* a){
	if (!vazia(a)){
		printf("%d ", a->dado);		//mostra raiz
		imprime(a->esquerda);	//mostra lado esquerdo
		imprime(a->direita);		//mostra lado direito
	}
}

//-------------------------INSERE--------------------------------
void inserir(No1** endPonteiroNo, int x){
	if (*endPonteiroNo == NULL){
		*endPonteiroNo = (No1*)malloc(sizeof(No1));
		(*endPonteiroNo)->dado = x;
		(*endPonteiroNo)->esquerda = NULL;
		(*endPonteiroNo)->direita = NULL;
	}
	else{
		if (x < (*endPonteiroNo)->dado){
			inserir(&(*endPonteiroNo)->esquerda, x);
		}		
		else {
			inserir(&(*endPonteiroNo)->direita, x);
		}
	}
}

//-------------------BUSCA-------------------------------------
int busca(No1* a, int num){
	if(a==NULL){
		//puts("valor nao existe \n");
		return 0;
	}
	else{
		if(num==a->dado){
			printf("\n%d\n",&a->dado);
			return 1;		
		}
		else if(busca(a->esquerda, num)){
			return 1;
		}
		else if(busca(a->direita, num)){
			return 1;
		}	
	}
}

//-------------------------LIBERA MEMÓRIA----------------------
No1* liberaMemoria(No1* a){
	if (!vazia(a)){
		liberaMemoria(a->esquerda);	
		liberaMemoria(a->direita);
		free(a);			
	}
	return NULL;
}

//--------------------------TAMANHO DA ARVORE----------------------------
int max(int a, int b){
	return (a>b) ? a : b; 
}

int tamanhoArvore(No1* a){
	if(vazia(a)){
		return -1;
	}
	else{
		return 1 + max(tamanhoArvore(a->esquerda), tamanhoArvore(a->direita));
	}
}

//----------------------------REMOCAO------------------------------
void remover(No1 **no, int valor) {
	No1 *paiDoMaior = NULL;
	No1 *pai = NULL;
	No1 *pNo = *no;
	No1 *a =  NULL;	
	No1 *b = NULL;
;
	if (pNo != NULL) {
		
		while (pNo) {
				 if (pNo->dado==valor) break;
				 if (valor < pNo->dado) {
				 	
					pai = pNo;
					pNo = pNo->esquerda;
				 }
			else if (valor > pNo->dado) {
				if (pNo->dado==valor) break;
				pai = pNo;
				pNo = pNo->direita;
			}
		}
		printf ("Numero: %d Endereco: %d\n", pNo->dado,&pNo->dado);
		system ("pause");
		if (pNo->esquerda == NULL && pNo->direita == NULL) {			
			printf("%d\n",no);
			if (pai != NULL && pai->dado < pNo->dado) pai->direita = NULL;
			else if  (pai != NULL) pai->esquerda = NULL;
			pNo = NULL;
			printf("%d\n",pNo);
			free(pNo);
		}
		else if (pNo->esquerda == NULL) {
			if (pai != NULL && pai->dado < (*no)->dado) pai->direita = pNo->direita;
			else if  (pai != NULL) pai->direita = (*no)->esquerda;
			pNo->direita = NULL;
			pNo = NULL;
			free (pNo); 
		}
		else if (pNo->direita == NULL) {
			if (pai != NULL && pai->dado < pNo->dado) pai->direita = pNo->direita;
			else if  (pai != NULL) pai->esquerda = pNo->esquerda;
			pNo->esquerda = NULL;
			pNo = NULL;	
			free(pNo);
		}
		
		else { 
			printf("entrei no quarto caso\n");
			a = Maior(pNo->esquerda); 
	        paiDoMaior = penultimoNo(pNo->esquerda); 
			a->esquerda = pNo->esquerda;         
	        a->direita = pNo->direita;
			if (paiDoMaior->direita == a) paiDoMaior->direita = NULL; 
				else if (paiDoMaior->esquerda == a) paiDoMaior->esquerda = NULL; 
				else if (paiDoMaior == a) printf("Maior da esquerda e seu pai sao os mesmos\n");
				else printf("Erro na verificação do pai do maior numero\n");
			if(pai != NULL && pai->esquerda == pNo) {
					pai->esquerda = a;
					}
				else if (pai != NULL && pai->direita == pNo) {
					pai->direita = a;
				}
				else if (pai == NULL){ 
					(*no) = a; 
					
					printf ("No removido!\nA agora eh: %d\n",(*no)->dado);
				}
			pNo->esquerda = pNo->direita = NULL;
	        free(&pNo); 
			pNo = NULL;
			
		}
	}
}
