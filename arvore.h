#include <stdio.h>
#include <stdlib.h>
typedef struct no No;
struct no{
	int dado;
	No *esquerda;
	No *direita;
};

//--------------------VERIFICA-VAZIO-------------------------------
int vazia(No* empty){
	return empty==NULL;
}

//-------------------------IMPRIME--------------------------------
void imprime(No* a){
	if (!vazia(a)){
		printf("%d ", a->dado);		//mostra raiz
		imprime(a->esquerda);	//mostra lado esquerdo
		imprime(a->direita);		//mostra lado direito
	}
}

//-------------------------INSERE--------------------------------
void inserir(No** endPonteiroNo, int x){
	if (*endPonteiroNo == NULL){
		*endPonteiroNo = (No*)malloc(sizeof(No));
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
int busca(No* a, int num){
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
No* liberaMemoria(No* a){
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

int tamanhoArvore(No* a){
	if(vazia(a)){
		return -1;
	}
	else{
		return 1 + max(tamanhoArvore(a->esquerda), tamanhoArvore(a->direita));
	}
}


