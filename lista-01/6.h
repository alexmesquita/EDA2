#ifndef EXERCICIO_6
#define EXERCICIO_6

#define NULO -1
#define VETOR_CHEIO -2
#define ELEMENTO_NAO_ENCONTRADO -3
#define VETOR_VAZIO -4
#define TAMANHO 8

extern void menu();
extern int *criarVetor();
extern int sair(int *vetor);
extern int printVetor(int const *vetor);
extern int excluirElemento(int *vetor, int const valor);
extern int inserirElemento(int *vetor, int const valor);
extern int buscaInterpolacao(int const *vetor, int const valor);


#endif
