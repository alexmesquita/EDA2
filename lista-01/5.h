#ifndef EXERCICIO_5
#define EXERCICIO_5

#define NULO -1
#define VETOR_CHEIO -2
#define ELEMENTO_NAO_ENCONTRADO -3
#define VETOR_VAZIO -4
#define TAMANHO 8
#define INICIALIZACAO_VETOR -1

extern void menu();
extern int *criarVetor();
extern int sair(int *vetor);
extern int printVetor(int const *vetor);
extern int printElementos(int const *vetor);
extern int excluirElemento(int *vetor, int const valor);
extern int inserirElemento(int *vetor, int const valor);
extern int buscaBinariaAnel(int const *vetor, int const valor);

static int begin=0;
static int end=-1;

#endif
