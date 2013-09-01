#include <iostream>
#include "6.h"

using namespace std;

void menu()
{
	cout << "1 - Inserir Elemento" << endl;
	cout << "2 - Apagar Elemento" << endl;
	cout << "3 - Busca por Interpolacao" << endl;
	cout << "4 - Visualizar Vetor" << endl;
	cout << "5 - Sair" << endl;
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
	for(int i = 0; i <= end; i++)
	{
		cout << vetor[i] << endl;
	}
	if(end<0)
	{
		cout << "O vetor esta vazio" << endl;
	}
	return 0;
}

int inserirElemento(int *vetor, int const valor)
{
	if(!vetor)
	{
		return NULO;
	}
	if(end<TAMANHO-1)
	{
		end++;
		vetor[end]=valor;
	}
	else
	{
		return VETOR_CHEIO;
	}
	
	int temp=0;
	
	for(int i=0;i < end; i++)
	{
		if(vetor[end]<vetor[i])
		{
			temp=vetor[end];
			vetor[end]=vetor[i];
			vetor[i]=temp;
		}
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
	
	int position = buscaInterpolacao(vetor, valor);
	if(position==NULO)
	{
		return NULO;
	}
	
	else if(position==ELEMENTO_NAO_ENCONTRADO)
	{
		return ELEMENTO_NAO_ENCONTRADO;
	}
	
	for(position; position<end; position++)
	{
		vetor[position]=vetor[++position];
	}
	end--;
	return 0;
}




int buscaInterpolacao(int const *vetor, int const valor)
{
	int begin = 0, mid=0, endAuxiliar=end;
	if(endAuxiliar==NULO)
	{
		return VETOR_VAZIO;
	}
	if(!vetor)
	{
		return NULO;
	}
	while(begin<=endAuxiliar)
	{
		
		if(endAuxiliar != begin)
		{
		cout << begin << "-" << end << endl;
			mid = begin + (endAuxiliar-begin) * (valor-vetor[begin]) / (vetor[endAuxiliar]-vetor[begin]);
		}
		if(vetor[mid] > valor)
		{
			endAuxiliar=mid-1;
			if(vetor[endAuxiliar]<valor)
			{
				return ELEMENTO_NAO_ENCONTRADO;
			}
		}
		else if(vetor[mid] < valor)
		{
			begin=mid+1;
			if(vetor[begin] > valor)
			{
				return ELEMENTO_NAO_ENCONTRADO;
			}
		}
		else
		{
		cout << "chegou 6" << endl;
			return mid;
		}
	}
	
	return ELEMENTO_NAO_ENCONTRADO;

}
