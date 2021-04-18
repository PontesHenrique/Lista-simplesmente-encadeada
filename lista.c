#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#include "lista.h"

#ifndef _LISTA_C_
#define _LISTA_C_

struct no
{
	int id;
	int idade;
	int cpf;
	int conta;
	int saldo;
	struct no *proximoNo;
};

No *criarNo(int id){
	
	No *no = (No*)malloc(sizeof(No));
	if(no){
		no->id = id;
		no->idade = 0;
		no->cpf = 0;
		no->conta = 0;
		no->saldo = 0;
		no->proximoNo = NULL;
	}
	return no;
}

listaVazia(No *cabecaLista){//verifica se a lista é vazia
	return (cabecaLista == NULL);
}

int tamanhoLista(No *cabecaLista){//calcula o tamanho da lista
	
	int tamanho = 0;
	while(cabecaLista){//enquanto existirn elemento na lista
		tamanho ++;//incrementa o tamanho
		cabecaLista = cabecaLista->proximoNo;
	}
	return tamanho;
}

int inserir(No **cabecaLista, int id){//insere elemnto no início da lista
	
	No *aux = criarNo(id);
	if(aux){
		aux->proximoNo = *cabecaLista;
		*cabecaLista = aux;
		return 1;//retorna 1 se sucesso na operação
	}
	return 0;
}

int inserirFinal(No **cabecaLista, int id){//insere no final da lista
	
	if(listaVazia(*cabecaLista)){//se a lista está vazia
		return inserir(cabecaLista, id);//insere no início da lista
	}else{
		No *aux = criarNo(id);
		if(aux){
			No *flag = *cabecaLista;
			while(flag->proximoNo){//percorre a lista até chegar no final
				flag = flag->proximoNo;
			}
			flag->proximoNo = aux;//insere elemento no final da lista
			return 1;
		}
	}
	return 0;
}

int inserirOrdenado(No **cabecaLista, int id){//insere elemento oredenado na lista
	
	if(listaVazia(*cabecaLista)){//se a lista está vazia
		return inserir(cabecaLista, id);//insere no início da lista
	}
	
	No *novo = criarNo(id);
	if (novo){
		No *anterior = NULL;
		No *aux = *cabecaLista;
		while(aux && aux->id < id){//percorre a lista até achar o local de inserção
			anterior = aux;
			aux = aux->proximoNo;
		}
		if(anterior == NULL){//significa que o elemento será inserido no início da lista
			novo->proximoNo = *cabecaLista;
			*cabecaLista = novo;
			return 1;
		}//elemento será inserido no local ordenado no meio ou no final da lista
		novo->proximoNo = anterior->proximoNo;
		anterior->proximoNo = novo;
		return 1;
	}
	return 0;
}

int buscaElemento(No *cabecaLista, int id)
{
	if(listaVazia(cabecaLista)){
		return 0;
	}
	while(cabecaLista){//percorre a lista para encontrar o elemento
		if(cabecaLista->id == id){
			return 1;//se encontrou retorna 1
		}
		cabecaLista = cabecaLista->proximoNo;
	}
	return 0;
}

void imprimeLista(No *cabecaLista, char *mensagem){//imprime a lista
	
	printf("%s", mensagem);
	while(cabecaLista){//percorre a lista
		printf("%d -> ", cabecaLista->id);//imprime a lista
		cabecaLista = cabecaLista->proximoNo;
	}
	printf(" NULL\n\n");
}

void limparLista(No **cabecaLista){//libera memória alocada
	No *prox = NULL;
	No *aux = *cabecaLista;
	while(aux){
		prox = aux->proximoNo;
		free(aux);
		aux = prox;
	}
	*cabecaLista = NULL;
}

int removeElemento(No **cabecaLista, int id){//remove elemento da lista
	
	No *anterior = NULL;
	No *aux = *cabecaLista;
	int flag = 0;
	while(aux){//procura o elemento
		if(aux->id == id){//se encontrar
			flag = 1;
			break;
		}
		anterior = aux;
		aux = aux->proximoNo;
	}//fim do while
	
	if(flag){//se achou elemento
		if(anterior == NULL){//remove no inicio da lista
			*cabecaLista = aux->proximoNo;
			free(aux);
			return 1;
		}
		//remove elemento encontrado no meio ou no final da lista
		anterior->proximoNo = aux->proximoNo;
		free(aux);
		return 1;
	}
	return 0;
}

int validarResp(char *mensagem, int padrao) {//função para confirmar comando pelo usuário
   int op;
   char cPadrao = (padrao ? 's' : 'n');

   do {
      printf("\n%s [S ou N] %c", mensagem, cPadrao);
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'S' && op != 'n' && op != 'N' && op != 13);

    if(op == 13)
        return padrao;

   return ((op == 's' || op == 'S') ? 1 : 0);
}

#endif
