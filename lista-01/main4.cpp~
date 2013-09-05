#include <iostream>
#include "4.h"

using namespace std;

int main()
{
	int *vetor = criarVetor();
	Indice *indice = criarIndice(vetor);
	
	int opcao=0;
	int elemento=0;
	char excluir='n';
	
	while(true)
	{
		menu();
		cin >> opcao;
		
		if(opcao==1)
		{
			cout << "Elemento: ";
			cin >> elemento;

			int resultado = buscaSequencial(elemento, vetor, indice);

			if(resultado==-1)
				cout << "Valor nao encontrado" << endl;
			else
			{
				cout << "Valor encontrado na posicao " << resultado << endl;
			
				cout << "Deseja excluir esse elemento? (s/n): ";
				cin >> excluir;
			
				if(excluir=='s')
					indice = excluirElemento(resultado, vetor);
			}
		}
		else if(opcao==2)
		{
			cout << "Elemento: ";
			cin >> elemento;
			
			inserirElemento(elemento, vetor);
		}
		else if(opcao==3)
		{
			visualizarVetor(vetor);
		}
		else
			break;
	}
	
	return 0;
}
