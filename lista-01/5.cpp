#include <iostream>
#include <vector>

using namespace std;

static const int tamVetor = 8;
static const int inicializacaoVetor = -1;

int encontrarBeginEnd(vector<int> vetor, int *begin, int *end)
{
	bool existeVazio = false;

	for(unsigned int i=0;i<vetor.size();i++)
	{
		if(vetor[i]<0)
		{
			*end = (i-1)%vetor.size();
			
			existeVazio = true;
		}
		else if(vetor[i]>=0 && existeVazio)
		{
			*begin = i;
			break;
		}
	}
	
	return 0;
}

int buscaBinariaAnel(vector<int> vetor, int valor)
{
	int begin = 0, end=vetor.size()-1;
	encontrarBeginEnd(vetor, &begin, &end);
	
	cout << begin << endl;
	cout << end << endl;
	
	int mid = 0;
	
	while(begin!=end)
	{
		if(begin>end)
		{
			mid = (begin+end+(int)vetor.size())/2;
			mid%=vetor.size();
		}
		else if(begin<end)
		{
			mid = (begin+end)/2;
		}
		if(valor==vetor[mid])
		{
			return mid;
		}
		else if(valor>vetor[mid])
		{
			begin = mid+1;
		}
		else
		{
			end = mid-1;
		}
		
	}
	
	if(vetor[begin]==valor)
	{
		return begin;
	}
	
	return -1;
}

int main()
{
	vector<int> vetor(tamVetor, inicializacaoVetor);
	vetor[4] = 4;
	vetor[5] = 5;
	vetor[6] = 6;
	vetor[7] = 7;
	vetor[0] = 8;
	vetor[1] = 9;
	vetor[2] = 10;
	
	int valor = 0;
	cin >> valor;
	
	cout << "Valor encontrado na posicao " << buscaBinariaAnel(vetor,valor) << endl;
	return 0;
}

