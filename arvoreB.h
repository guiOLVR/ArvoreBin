#include<stdio.h>
#include<stdlib.h>
#define red 0
#define black 1

typedef struct no No;
struct no {
	int cor;
	int dado;
	No *esquerda;
	No *direita;
	No *pai;
};
void Corrige(No *n);
void CorrigeCaso3(No* n);

//--------------------------------------------------------------------------
No *tio(No *sobrinho) {
	No *Tio = NULL;
	     if (sobrinho->pai == NULL) return NULL; 
	else if (sobrinho->pai->pai == NULL) return NULL; 
	else if (sobrinho->pai == sobrinho->pai->pai->esquerda) return (Tio = sobrinho->pai->pai->direita); 
	else if (sobrinho->pai == sobrinho->pai->pai->direita) return (Tio = sobrinho->pai->pai->esquerda); 
}
//-------------------------------------------------------------------------
No *avo(No *neto) {
	No *avo = NULL; 
	if (neto->pai != NULL)
	 avo = neto->pai->pai; 
	return avo;
}

//--------------------------------------------------------------------------
void rotacionar_esquerda(No *no) { 
	
	No *aux =(No*)  malloc(sizeof(No));
	aux = NULL;
	aux = no->esquerda; 
	no->esquerda = no->pai; 	

	no->pai = avo(no); 
	if (no->esquerda != NULL) no->esquerda->pai = no;
	if (no->esquerda != NULL) no->esquerda->direita = aux; 
	if (no->pai != NULL) no->pai->esquerda = no; 
}

//------------------------------------------------------
void rotacionar_direita(No *no) { 
	
	No *auxEsq = (No*) malloc(sizeof(No));
	auxEsq = NULL;
	auxEsq = no->direita;

	no->direita = no->pai; 
	no->pai = avo(no); 
	if (no->direita != NULL) no->direita->pai = no; 
    if (no->direita != NULL) no->direita->esquerda = auxEsq; 
	if (no->pai != NULL) no->pai->direita = no; 

}

//----------------------------------------------------
void CorrigeCaso5(No* n) {

	No *Avo = avo(n);
		n->pai->cor = black;
		Avo->cor = red;
		if ((n == n->pai->esquerda) && (n->pai == Avo->esquerda)) {
			
			rotacionar_direita(n->pai);
		} 
		else {
			
			rotacionar_esquerda(n->pai);
		}
}

//----------------------------------------------------------
void CorrigeCaso4(No* n) {

	No *Avo = avo(n);
	
		if ((n == n->pai->direita) && (n->pai == Avo->esquerda)) {

			rotacionar_esquerda(n);
			n = n->esquerda;
		}	 
		else if ((n == n->pai->esquerda) && (n->pai == Avo->direita)) {

			rotacionar_direita(n);
			n = n->direita;
		}
		CorrigeCaso5(n);
}

//-----------------------------------------------------------
void Corrige(No* n) {
	No *Tio = (tio(n));
	if (n->pai == NULL)	{
		n->cor = black; 
	}
	
	else if (n->pai->cor == black ){ 
		return;
	}
	
	else if ((Tio != NULL) && (Tio->cor == red)) { 
		CorrigeCaso3(n);
		
	}
	else
	{
		CorrigeCaso4(n);
				
	}
}

//-----------------------------------------------------
void CorrigeCaso3(No* n) { 
	No *Tio = tio(n);
	No *Avo = avo(n); 
	n->pai->cor = black; 
	Tio->cor = black; 
	Avo->cor = red; 
	Corrige(Avo); 


}
//--------------------------------------------------
int buscaB(No* a, int num){
	if(a==NULL){
		//puts("valor nao existe \n");
		return 0;
	}
	else{
		if(num==a->dado){
			printf("\n%d\n",&a->dado);
			return 1;		
		}
		else if(buscaB(a->esquerda, num)){
			return 1;
		}
		else if(buscaB(a->direita, num)){
			return 1;
		}	
	}
}

//---------------------------------------------------
void inserirB(No **endPonteiroNo, int dado) {
	No *pai= NULL;
	if (*endPonteiroNo == NULL) {		
		printf ("dado %d  ",dado);
		*endPonteiroNo = (No *) malloc (sizeof(No));
		printf ("%d\n",*endPonteiroNo);
		(*endPonteiroNo)->dado = dado;
		(*endPonteiroNo)->esquerda = NULL;
		(*endPonteiroNo)->direita = NULL;
		(*endPonteiroNo)->pai = pai;
		(*endPonteiroNo)->cor = NULL;
		Corrige(*endPonteiroNo);

		
	}
	else {
		
		if (dado>((*endPonteiroNo)->dado)) {
			inserirB (&(*endPonteiroNo)->direita, dado);

		}
		else {
			inserirB (&(*endPonteiroNo)->esquerda, dado);

		}
	} 
}
