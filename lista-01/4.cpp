#include <iostream>
#include <vector>

using namespace std;

static const int quant=200;
static const int tamIndice=quant/10;
static const int quantIndice = 10; //Como os índices correspondem a 10% da quantidade de elementos só podem existir 10

typedef struct _Indice
{
	int info;
	int posicao;
}Indice;

vector<int> criarVetor()
{
	vector<int> vetor;
	
	for(int i=0;i<quant;i++)
		vetor.push_back(i*2);
	
	return vetor;
}

Indice *criarIndice(vector<int> vetor)
{
	Indice *indice = new Indice[tamIndice];
	
	for(int i=0;i<quantIndice;i++)
	{
		indice[i].info = vetor[i*tamIndice];
		indice[i].posicao = i*tamIndice;
	}
	
	return indice;
}

int buscaSequencial(int valor, vector<int> vetor, Indice *indice)
{
	int posicao=0;
	
	for(int i=0;i<tamIndice;i++)
	{
		if(valor < indice[i].info)
		{
			posicao = indice[i-1].posicao;
			break;
		}
		
		else
			posicao = indice[i].posicao;
	}
	
	for(int i=posicao;i<posicao+tamIndice;i++)
	{
		if(valor==vetor[i])
			return i;
	}
	
	return -1;
}

int main()
{
	vector<int> vetor = criarVetor();
	Indice *indice = criarIndice(vetor);
	
	int valor;
	cin >> valor;
	
	int resultado = buscaSequencial(valor, vetor, indice);
	
	if(resultado==-1)
	{
		cout << "Valor nao encontrado" << endl;
		return -1;
	}
	
	cout << "Valor encontrado na posicao " << resultado << endl;	
	return 0;
}
