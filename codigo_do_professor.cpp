#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <sstream>
#include <time.h>

using namespace std;

struct item //No
{
	list<int> a;
};

// string toStr(item x){}

// int variavelRamificacao(item, x, int n){}

int main()
{
	srand(time(0)); // Iniciar gerador de numeros pseudoaleatorios

	int n = 5;

	stack<item> P;

	item raiz;

	raiz.a = list<int>();

	P.push(raiz);

	while (P.size() > 0)
	{
		item atual = P.top();
		P.pop();
		cout << "atual: " << toStr(atual) << endl; // Apenas para Visualizacao

		if (solucaoCompleta(atual, n) == true)
			continue; // Substituir por: verificacao de viabilidade, atualizacao da melhor solucao conhecida

		if (podaPorInviabilidade(atual, n) == true)
			continue; // Substituir por: poda

		if (podaPorOtimalidade(atual, n) == true)
			continue; // Substituir por: poda

		// Se codigo chegou aqui é pq <atual> nao foi podada, nem é solucao viavel
		// Nesse caso, vamos ramificar
		int var = variavelRamificacao(atual, n);

		item filho0 = atual;
		filho0.a.push_back(-var);

		item fihlo1 = atual;
		filho1.a.push_back(var);

		P.push(filho1);
		P.push(filho0);
	}
	return 0;
}