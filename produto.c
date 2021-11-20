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
#include <stdlib.h>
#include <string.h>

void inserir(produto *lst){
	int cod;	
	produto *p, *q, *nova;
	nova=(produto*)malloc(sizeof(produto));
	scanf("%d", &cod);
	nova->codigo=cod;
	p=lst;
	q=lst->prox;
	while(q!=NULL && q->codigo!=cod){		
		p=q;
		q=q->prox;
	}
	if(q!=NULL && q->codigo==cod){
		free(nova);
		printf("Erro ao inserir o produto %d\n", cod);
	}
	else{
		scanf("%s", nova->nome);
		scanf("%d", &nova->quantidade);
		scanf("%f", &nova->preco);
		if(q==NULL){
			nova->prox=NULL;
		}
		else{
			nova->prox=q;
		}
		p->prox=nova;
		printf("Produto %d inserido com sucesso\n", cod);
	}
}

void excluir(produto *lst){
	int n;
	produto *p, *q;
	p=lst;
	q=lst->prox;
	scanf("%d", &n);
	while(q!=NULL && q->codigo!=n){
		p=q;
		q = q->prox;
	}
	
	if(q!=NULL && q->codigo==n){
		if(q!=NULL){
			printf("Produto %d excluido com sucesso\n",n);
			p->prox = q->prox;
			free(q);
		}
		else{
			printf("Produto %d excluido com sucesso\n",n);
			p->prox=NULL;
			free(q);
		}
	}
	else{
		printf("Produto %d nao cadastrado\n", n);
	}
}

void consultar(produto *lst){
	char cadeia[30];
	produto *p;
	scanf("%s", cadeia);
	for(p=lst;p!=NULL;p=p->prox){
		if(strstr(p->nome, cadeia) != NULL){
			printf("%d - %s - %d - %.2f\n", p->codigo, p->nome, p->quantidade, p->preco);
		}
	}
}

void sair(produto *lst){
	FILE *file;
	produto *p;
	file = fopen("compra.txt","w");
	if(file != NULL){
		for(p=lst->prox;p!=NULL;p=p->prox){		
			if (p->quantidade <= 30 && p->codigo!=0){
				printf("%d - %s - %d\n", p->codigo, p->nome, p->quantidade);
				fprintf(file, "%d - %s - %d\n",p->codigo, p->nome, p->quantidade);
			}			
		}
	}
	fclose(file);
}

void atualizar(produto *lst){
	char car[3];
	int n;
	produto *p;
	p=lst->prox;
	scanf("%s %d", car, &n);
	while(p!=NULL && p->codigo!=n){
		p=p->prox;
	}
	if(strcmp(car,"-q")==0 && p!=NULL && p->codigo==n){
		scanf("%d", &p->quantidade);
		printf("Produto %d atualizado com sucesso\n", n);
	}
	else if (strcmp(car,"-v")==0 && p!=NULL && p->codigo==n){
		scanf("%f", &p->preco);
		printf("Produto %d atualizado com sucesso\n", n);
	}
	else{
		printf("Produto %d nao cadastrado no sistema\n", n);
	}
}

void vender(produto *lst){
	float soma=0.00;
	int i;
	produto *q;
	do{
		scanf("%d", &i);
		q=lst->prox;
		while(q!=NULL && q->codigo!=i){		
			q=q->prox;
		}		
		if(q!=NULL && q->codigo==i && q->quantidade == 0){
			printf("Produto em falta no estoque\n");
		}
		else if(q!=NULL && q->codigo==i && q->quantidade > 0){
			soma=soma+q->preco;
			q->quantidade --;
			printf("%d ", q->codigo);
			printf("%s ",q->nome);
			printf("%.2f\n", q->preco);
		}
		else if (i!=0 && q==NULL){
			printf("Produto nao cadastrado\n");
		}
	}while(i != 0);
	
	printf("-------------\n");
	printf("Total %.2f\n", soma);
}

void help (produto *lst){
	printf("Escolhi lista simples encadeada pelo fato de ser o método na qual eu me adaptei melhor. Seu método de trabalhar é mais facil, e como eu me encontro com dificuldade nessa matéria, escolhi trabalhar com o mais simples.\n");
}

void importar(produto *lst){
	char cadeia[50], c[50];
	int x, i, cod, qua, y;
	float pre;
	FILE *file, *file2;
	produto *p, *q, *nova;
	
	scanf("%s", cadeia);
	file = fopen(cadeia, "r");
	if(file != NULL){
		fscanf(file, "%d", &x);
		while(y<x){
			nova=(produto *)malloc(sizeof(produto));
			p=lst;
			q=lst->prox;

			fscanf(file,"%d", &cod);
			while(q!=NULL && q->codigo!=cod){		
				p=q;
				q=q->prox;
			}
			
			nova->codigo=cod;
			
			fscanf(file,"%[^0-9]",c);
			for(i=1;i<50 && c[i]!=';';i++){
				c[i-1]=c[i];				
			}
			if(c[i]==';'){
				c[i]=' ';
				c[i-1]=' ';
			}
			strcpy(nova->nome,c);
	
			fscanf(file,"%d",&qua);
			nova->quantidade=qua;
			
			fscanf(file, "%[^0-9]", c);
			fscanf(file,"%f", &pre);
			fscanf(file, "%[^\n]", c);			
			nova->preco=pre;
			
			if(q==NULL){			
				nova->prox=q;
				p->prox=nova;
			}
			else{
				free(nova);
			}
			y++;
		}

		printf("%d Produtos importados\n", x);
		file2 = fopen(cadeia, "w");
		if(file2 != NULL){
			fprintf(file2, "0");
		}
	
	fclose(file2);
	fclose(file);
	}
}

void relatorio(produto *lst){
	char v[]="abcçdefghijklmnopqrstuvwxyz";
	char v2[]="ABCÇDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, x=0;
	FILE *file;
	produto *p;
	p=lst->prox;
	file=fopen("Relatorio.txt", "w");
	if(file != NULL){
		for(i=0;i<=27;i++){
			while(p!=NULL){
				if(strncmp(&v[i],p->nome, 1)==0 || strncmp(&v2[i],p->nome, 1)==0){
					if(x==0){
						printf("%c\n", v2[i]);
						fprintf(file, "%c\n", v[i]);
					}
					printf("   %d - %s - %d - %.2f\n", p->codigo, p->nome, p->quantidade, p->preco);
					fprintf(file, "   %d - %s - %d - %.2f\n", p->codigo, p->nome, p->quantidade, p->preco);
					x=1;		
				}
				p=p->prox;
			}
			x=0;
			p=lst->prox;
		}
	}
	fclose(file);
}

void carregaBin (produto *lst){	
	FILE *file;
	produto *p, *q;
	q=lst;
	file = fopen("produto.dat", "rb");
	if(file != NULL){
		p=(produto*)malloc(sizeof(produto));
		fread(p,sizeof(produto), 1, file);
		while(!feof(file)){
			q->prox=p;
			p->prox=NULL;
			q=p;
			p=(produto*)malloc(sizeof(produto));
			fread(p,sizeof(produto), 1, file);
		}
		free(p);
		fclose(file);
	}
}

void salvaBin(produto *lst){
	FILE *file;
	produto *p;
	p=lst->prox;
	file = fopen("produto.dat","wb");
	
	if(file != NULL){
		while(p!=NULL){
			fwrite(p,sizeof(produto), 1, file);
			p=p->prox;	
		}
	fclose(file);
	}
	
}
