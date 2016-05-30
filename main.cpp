#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"
#include "arvore.h"
#include <string.h>

main(){
	int tipo=0;
	puts("1.Arvore Binaria\n2.Arvore Balanceada");
	scanf("%d",&tipo);
	
	if(tipo == 1){
		int num,b;
		int opcao = 0;
		No1* arvore = NULL;
		
		while(opcao !=6){
			puts("Escolha uma opcao: \n 1.Iserir \n 2.Imprimir arvore \n 3.Tamanho arvore \n 4.Buscar valor \n 5.Remover \n6.Sair \n");
			scanf("%d", &opcao);
			switch(opcao){
				case 1:	system("cls");
						puts("Digitte o valor: ");
						scanf("%d", &num);
						inserir(&arvore, num);
						break;
		
				case 2:	system("cls");
						imprime(arvore);
						puts("\n");
						break;
						
				case 3: system("cls");
						b=tamanhoArvore(arvore);
						printf("%d\n", b);
						break;
						
				case 4: system("cls");
						scanf("%d", &num);
						busca(arvore, num);
						break;
				case 5: system("cls");
						scanf("%d",&num);
						remover(&arvore, num);
						break;		
			}
		}
	}
	else if(tipo == 2){
			int num,b;
		int opcao = 0;
		No* arvore = NULL;
		
		while(opcao !=6){
			puts("Escolha uma opcao: \n 1.Iserir \n 2.Buscar valor \n 3.Imprimi \n 4.Remover \n6.Sair \n");
			scanf("%d", &opcao);
			switch(opcao){
				case 1:	system("cls");
						puts("Digitte o valor: ");
						scanf("%d", &num);
						inserirB(&arvore, num);
						break;
						
				case 2: system("cls");
						scanf("%d", &num);
						buscaB(arvore, num);
						break;
				case 3: system("cls");
						imprimeB(arvore);
						break;
				case 4: system("cls");
						scanf("%d", &num);
						puts("\nPuutz!\n");
						break;		
			}
		}
	}
	else{
		system("cls");
		puts("\n\nOpcao incorreta!!\n\n");
	}
}
