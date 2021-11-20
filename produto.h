/*****************************************
*                                        *
*Paulo Henrique Lima de Paula            *
*Trabalho 3                              *
*Disciplina: Algortimos e Programação II *
* Professor: Ronaldo Fiorilo             *
*                                        *
******************************************/

struct prod{
	int codigo;
	char nome [50];
	int quantidade;
	float preco;
	struct prod *prox;
};

typedef struct prod produto;


void inserir(produto *lst);
void atualizar(produto *lst);
void excluir(produto *lst);
void sair(produto *lst);
void vender(produto *lst);
void consultar(produto *lst);
void importar(produto *lst);
void relatorio(produto *lista);
void help (produto *lista);
void carregaBin(produto *lista);
void salvaBin(produto *lista);

