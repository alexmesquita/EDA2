#include <iostream>
#include <vector>

using namespace std;

static const int quant=11;
int tamVetor=quant;
static const int tamIndice=10;
int quantIndice = 0;

typedef struct _Indice
{
	int info;
	int posicao;
}Indice;

void menu()
{
	cout << "1 - Busca Sequencial" << endl;
	cout << "2 - Inserir Elemento" << endl;
	cout << "3 - Sair" << endl;
}

void quantidadeIndices()
{
	quantIndice = 0;
	int quantidadeMaxima = tamVetor;
	
	while(quantidadeMaxima>0)
	{
		quantidadeMaxima-=tamIndice;
		quantIndice++;
	}
}

vector<int> criarVetor()
{
	vector<int> vetor;
	
	for(int i=0;i<quant;i++)
		vetor.push_back(i);
	
	return vetor;
}

Indice *criarIndice(vector<int> vetor)
{
	quantidadeIndices();
	
	Indice *indice = new Indice[quantIndice];
	
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
	
	for(int i=0;i<quantIndice;i++)
	{
		if(valor < indice[i].info)
		{
			posicao = indice[i-1].posicao;
			break;
		}
		
		else
			posicao = indice[i].posicao;
	}
	
	for(int i=posicao;i<posicao+tamIndice || i<tamVetor;i++)
	{
		if(valor==vetor[i])
			return i;
	}
	
	return -1;
}

vector<int> excluirElemento(int posicao, vector<int> vetor, Indice *indice)
{
	char excluir = 'n';
	
	cout << "Excluir elemento? (s / n): " << endl;
	cin >> excluir;
	
	if(excluir == 's')
	{
		for(int i=posicao;i<quant;i++)
			vetor[i] = vetor[i+1];
			
		tamVetor--;
		
		indice = criarIndice(vetor);
				
		return vetor;
	}
	
	return vetor;
}

int main()
{
	vector<int> vetor = criarVetor();
	Indice *indice = criarIndice(vetor);
	
	int opcao = 0;

	while(true)
	{			
		menu();
		cin >> opcao;
	
		if(opcao==1)
		{
			int valor;

			cout << "Valor: ";
			cin >> valor;
		
			int resultado = buscaSequencial(valor, vetor, indice);
		
			if(resultado==-1)
			{
				cout << "Valor nao encontrado" << endl;
				return -1;
			}
	
			cout << "Valor encontrado na posicao " << resultado << endl;
		
			vetor = excluirElemento(resultado, vetor, indice);
		
			for(int i=0;i<tamVetor;i++)
				cout << vetor[i] << endl;
		}
		else
		{
			break;
		}
	}
	
	return 0;
}
