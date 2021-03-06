#include "4.h"
#include <iostream>

using namespace std;

static int tamVetor=0;

void menu()
{
	cout << "1 - Busca Sequencial" << endl;
	cout << "2 - Inserir Elemento" << endl;
	cout << "3 - Visualizar Vetor" << endl;
	cout << "4 - Sair" << endl;
	cout << "Opcao: ";
}

int quantidadeIndices()
{
	int quantIndices = 0;
	int quantTotal = tamVetor;
	
	while(quantTotal>0)
	{
		quantTotal-=TAM_INDICE;
		quantIndices++;
	}
	
	return quantIndices;
}

int *criarVetor()
{
	int *vetor = new int[QUANT_TOTAL];
	
	return vetor;
}

Indice *criarIndice(int *vetor)
{
	int quantIndice = quantidadeIndices();
	
	Indice *indice = new Indice[quantIndice];
	
	for(int i=0;i<quantIndice;i++)
	{
		indice[i].info = vetor[i*TAM_INDICE];
		indice[i].posicao = i*TAM_INDICE;
	}
	
	return indice;
}

void visualizarVetor(int *vetor)
{
	for(int i=0;i<tamVetor;i++)
		cout << vetor[i] << endl;
}

int inserirElemento(int elemento, int *vetor, Indice *indice)
{
	if(tamVetor==QUANT_TOTAL)
	{
		cout << "Impossível inserir elemento, vetor cheio..." << endl;
		return VETOR_CHEIO;
	}
	
	int posicao = buscaPosicao(elemento, indice);
	
	for(int i=posicao;i<tamVetor;i++)
	{
		if(elemento == vetor[i])
		{
			cout << "Impossível inserir elemento, elemento já existe no vetor..." << endl;
			return ELEMENTO_DUPLO;
		}
		else if(elemento < vetor[i])
		{
			for(int j=tamVetor;j>i;j--)
				vetor[j] = vetor[j-1];
			
			vetor[i] = elemento;
			tamVetor++;
			return 0;
		}
	}
	
	vetor[tamVetor] = elemento;
	tamVetor++;
	
	return 0;
}

Indice *excluirElemento(int posicao, int *vetor)//Esse método retornará o novo indice depois de excluir o elemento
{
	for(int i=posicao;i<tamVetor-1;i++)
		vetor[i] = vetor[i+1];
	
	tamVetor--;
	
	return criarIndice(vetor);
}

int buscaPosicao(int elemento, Indice *indice)
{
	int posicao=0;
	
	for(int i=1;i<quantidadeIndices();i++)
	{
		if(elemento < indice[i].info)
		{
			posicao = indice[i-1].posicao;
			break;
		}

		else
			posicao = indice[i].posicao;
	}
	
	return posicao;
}

int buscaSequencial(int elemento, int *vetor, Indice *indice)
{
	int posicao = buscaPosicao(elemento, indice);
	
	for(int i=posicao;i<posicao+TAM_INDICE || i<tamVetor;i++)
	{
		if(elemento==vetor[i])
			return i;
	}

	return ELEMENTO_INESISTENTE;
}

