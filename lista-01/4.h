#ifndef EXERCICIO_4
#define EXERCICIO_4

#define QUANT_TOTAL 11
#define TAM_INDICE 10

#define VETOR_CHEIO -1
#define ELEMENTO_DUPLO -2
#define ELEMENTO_INESISTENTE -3

typedef struct _Indice
{
	int info;
	int posicao;
}Indice;

extern int tamanhoVetor();
extern void menu();
extern int quantidadeIndices();

extern int *criarVetor();
extern Indice *criarIndice(int *vetor);

extern void visualizarVetor(int *vetor);

extern int inserirElemento(const int elemento, int *vector, Indice *indice);
extern Indice *excluirElemento(const int posicao, int *vetor);

extern int buscaPosicao(const int elemento, Indice *indice);
extern int buscaSequencial(const int elemento, int *vetor, Indice *indice);

#endif
