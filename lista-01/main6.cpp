#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "6.h"

using namespace std;

int main()
{
	int *vetor = criarVetor();
	if(!vetor)
	{
		cout <<"Erro ao Criar o vetor!" << endl;
		return-1;
	}
	int opcao = 0;
	int valor = 0;
	bool continuar = true;
	
	while(continuar)
	{
		menu();
		cin >> opcao;
		
		if(opcao==1)
		{
		
			cout << "Elemento: ";
			cin >> valor;
			
			int erro = inserirElemento(vetor, valor);
			
			switch(erro)
			{
				case NULO:
					cout << "Erro: Vetor Nulo" << endl;
				break;
				case VETOR_CHEIO:
					cout << "Erro: O vetor esta cheio" << endl;
				break;
				default:
					cout << "Elemento inserido com sucesso" << endl;
				
			}
			
		}
		else if(opcao==2)
		{
			cout << "Elemento: ";
			cin >> valor;
			
			int erro = excluirElemento(vetor, valor);
			
			switch(erro)
			{
				case NULO:
					cout << "Erro: Vetor Nulo" << endl;
				break;
				case VETOR_VAZIO:
					cout << "Erro: O vetor esta vazio!" << endl;
				break;
				case ELEMENTO_NAO_ENCONTRADO:
					cout << "Erro: O elemento nao foi encontrado!" << endl;
				break;
				default:
					cout << "Elemento apagado com sucesso" << endl;
			}
			
		}
		else if(opcao==3)
		{
			cout << "Elemento: ";
			cin >> valor;

			int resultado = buscaInterpolacao(vetor, valor);

			switch(resultado)
			{
				case NULO:
					cout << "Erro: Vetor Nulo" << endl;
				break;
				case VETOR_VAZIO:
					cout << "Erro: O vetor esta vazio!" << endl;
				break;
				case ELEMENTO_NAO_ENCONTRADO:
					cout << "Erro: O elemento nao foi encontrado!" << endl;
				break;
				default:
					cout << "Elemento encontrado na posicao: " << resultado << endl;
			}
		}
		else if(opcao==4)
		{
			int erro = printVetor(vetor);

			switch(erro)
			{
				case NULO:
					cout << "Erro: Vetor Nulo" << endl;
				break;
			}
		}
		else if(opcao==5)
		{
			continuar=sair(vetor);
			cout << "bye bye" << endl;
		}
		else
		{
			cout << "Opcao Invalida" << endl;
		}
		getchar();	
		getchar();
		system("clear");
	}
	
	return 0;
}
