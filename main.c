/*****************************************
*                                        *
*Paulo Henrique Lima de Paula            *
*Trabalho 3                              *
*Disciplina: Algortimos e Programação II *
* Professor: Ronaldo Fiorilo             *
*                                        *
******************************************/

#include "produto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char cadeia[50];
	
	produto *lista;
	lista=(produto*)malloc(sizeof(produto));
	lista->prox=NULL;
	
	carregaBin(lista);
	
	scanf("%s", cadeia);
	while(1){
				
		if (strcmp(cadeia,"inserir")==0){
			inserir(lista);
		}
		else if(strcmp(cadeia,"consultar")==0){		
			consultar(lista);
		}
		else if(strcmp(cadeia,"excluir")==0){			
			excluir(lista);
		}
		else if(strcmp(cadeia,"sair")==0){
			salvaBin(lista);
			sair(lista);
			return 0;
		}
		else if(strcmp(cadeia,"atualizar")==0){
			atualizar(lista);
		}
		else if(strcmp(cadeia,"vender")==0){
			vender(lista);
		}
		else if(strcmp(cadeia,"importar")==0){
			importar(lista);
		}
		else if(strcmp(cadeia,"relatorio")==0){
			relatorio(lista);
		}	
		else if(strcmp(cadeia,"help")==0){
			help(lista);
		}		

		
					
		scanf("%s", cadeia);
	}

	return 0;
}
