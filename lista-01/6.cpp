#include <iostream>
#include <vector>

using namespace std;

static const int vazio=-1;

int buscarIndices(vector<int> vetor, unsigned int *begin, unsigned int *end)
{
	*end=vetor.size()-1;
	for(unsigned int i=0; i<*end; i++)
	{
		if(vetor[i]==-1)
		{
			cout << i << endl;
			*end=i;
			break;
		}
		
	}
	return 0;
}


int buscaInterpolacao(vector<int> vetor, int valor)
{
	unsigned int begin = 0, end = 0;
	buscarIndices(vetor, &begin, &end);
	
	unsigned int mid = 0;
	
	while(begin<=end)
	{
		mid = begin + (end-begin) * (valor-vetor[begin]) / (vetor[end]-vetor[begin]);
		if(vetor[mid] > valor)
		{
			end=mid-1;
			if(vetor[end]<valor)
			{
				return -1;
			}
		}
		else if(vetor[mid] < valor)
		{
			begin=mid+1;
			if(vetor[begin] > valor)
			{
				return -1;
			}
		}
		else
		{
			return mid;
		}
		cout << begin <<"-"<< mid <<"-"<< end << endl;	
	}
	
	return -1;

}

int main()
{
	vector<int> vetor(20,-1);
	
	for(int i=0; i<20; i++)
	{
		vetor[i]=(i*10);
	}
	
	int valor=0;
	
	cin >> valor;
	
	int result = buscaInterpolacao(vetor, valor);
	
	cout << result << endl;
	
	return 0;
}

