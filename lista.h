#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct no No;

No *criarNo(int id);
int listaVazia(No *cabecaLista);
int tamanhoLista(No *cabecaLista);
int inserir(No **cabecaLista, int id);
int inserirFinal(No **cabecaLista, int id);
int inserirOrdenado(No **cabecaLista, int id);
int buscaElemento(No *cabecaLista, int id);
void imprimeLista(No *cabecaLista, char *mensagem);
void limparLista(No **cabecaLista);
int removeElemento(No **cabecaLista, int id);
int validarResp(char *mensagem, int padrao);

#endif

