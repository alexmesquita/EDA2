#include <iostream>
#include "5.h"

using namespace std;

static int begin=0;
static int end=-1;

void menu()
{
	cout << "1 - Inserir Elemento" << endl;
	cout << "2 - Apagar Elemento" << endl;
	cout << "3 - Busca Binaria(em Anel)" << endl;
	cout << "4 - Visualizar Vetor" << endl;
	cout << "5 - Visualizar Elementos" << endl;
	cout << "6 - Sair" << endl;
	cout << "Opcao: ";
}

int *criarVetor()
{
	int *vetor = new int[TAMANHO];
	
	if(!vetor)
	{
		return 0;
	}
	
	for(int i = 0; i<TAMANHO; i++)
	{
		vetor[i]=-1;
	}
	return vetor;
}
int sair(int *vetor)
{
	delete [] vetor;
	return 0;
}

int printVetor(int const *vetor)
{
	if(!vetor)
	{
		return NULO;
	}
	for(int i = 0; i < TAMANHO; i++)
	{
		if(i)
		{
			cout << ", ";
		}
		else
		{
			cout << "[";
		}
		cout << vetor[i];
		if(i+1==TAMANHO)
		{
			cout << "]" << endl;
		}
	}
	
	return 0;
}

int printElementos(int const *vetor)
{
	bool existeElemento=false;
	if(!vetor)
	{
		return NULO;
	}
	int i = begin;
	while(end>=0 && vetor[i]>=0)
	{
		existeElemento=true;
		if(i==begin)
		{
			cout << "[";
		}
		else
		{
			cout << ", ";
		}
		cout << vetor[i];
		i=(i+1)%TAMANHO;
		if(i==begin)
		{
			break;
		}
		
		
	}
	if(!existeElemento)
	{
		cout << "O vetor esta vazio" << endl;
	}
	else
	{
		cout << "]" << endl;
	}
	return 0;
}

int inserirElemento(int *vetor, int const valor)
{
	if(!vetor)
	{
		return NULO;
	}
	if(vetor[(end+1)%TAMANHO]<0)
	{
		end = (end+1)%TAMANHO;
		vetor[end]=valor;
	}
	else
	{
		return VETOR_CHEIO;
	}
	
	int j=begin;
	int temp=0;
	
	//laço que percorre do begin ao end ordenando as posições
	while(j != end)
	{
		if(vetor[end]<vetor[j])
		{
			temp=vetor[end];
			vetor[end]=vetor[j];
			vetor[j]=temp;
		}
		j=(j+1)%TAMANHO;
	}
	return 0;
}

int excluirElemento(int *vetor, int const valor)
{
	if(end==NULO)
	{
		return VETOR_VAZIO;
	}
	if(!vetor)
	{
		return NULO;
	}
	
	int position = buscaBinariaAnel(vetor, valor);
	if(position==NULO)
	{
		return NULO;
	}
	
	else if(position==ELEMENTO_NAO_ENCONTRADO)
	{
		return ELEMENTO_NAO_ENCONTRADO;
	}
	
	while(position!=begin)
	{
		vetor[position]=vetor[(position-1)%TAMANHO];
		position = (position-1)%TAMANHO;
		vetor[position] = NULO;
	}
	begin = (begin+1)%TAMANHO;
	return 0;
}


int buscaBinariaAnel(int const*vetor, int const valor)
{
	int mid = 0;
	
	int endAuxiliar = end;
	int beginAuxiliar = begin;
	
	if(end==NULO)
	{
		return VETOR_VAZIO;
	}
	if(!vetor)
	{
		return NULO;
	}
	
	while(beginAuxiliar!=endAuxiliar && endAuxiliar >= 0)
	{
		if(beginAuxiliar>endAuxiliar)
		{
			mid = (beginAuxiliar+endAuxiliar+TAMANHO)/2;
			mid%=TAMANHO;
		}
		else if(beginAuxiliar<endAuxiliar)
		{
			mid = (beginAuxiliar+endAuxiliar)/2;
		}
		if(valor==vetor[mid])
		{
			return mid;
		}
		else if(valor>vetor[mid])
		{
			beginAuxiliar = mid+1;
		}
		else
		{
			endAuxiliar = mid-1;
		}
	}
	
	if(vetor[beginAuxiliar]==valor)
	{
		return beginAuxiliar;
	}
	
	return ELEMENTO_NAO_ENCONTRADO;
}
