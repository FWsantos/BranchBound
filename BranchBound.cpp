#include <iostream>
#include <algorithm> // for copy.
#include <iterator> // for back_inserter
#include "mochila.cpp"
using namespace std;

Mochila best_pack;
double best_avaliacao;
double otimo_rl = 0;
double avaliacao_g = 0;
double load_g = 0;
int contador_avaliados  = 0;
int contador_criados = 0;
double best_limite = 0;
bool flag = false;

double RL(Mochila crianca, int indice, double load){
	vector<double> vpp = std::vector<double>(crianca.peso_valor.size(), 0); //valor por peso
	for (int i = indice; i < crianca.peso_valor.size(); ++i){
		vpp[i] = (crianca.peso_valor[i][VALOR]/crianca.peso_valor[i][PESO]);
	}

	int maximo;
	for (int i = 0; i < crianca.x.size() - indice; ++i)
	{
		maximo = distance(vpp.begin(), max_element(vpp.begin(), vpp.end()));
		vpp[maximo] = 0;

		if(load + crianca.peso_valor[maximo][PESO] <= crianca.capacidade){

			crianca.x[maximo] = 1;
			load = load + crianca.peso_valor[maximo][PESO];

		}else{

			crianca.x[maximo] = (crianca.capacidade - load)/crianca.peso_valor[maximo][PESO];

			return crianca.avaliacao();
		}
	}
	return crianca.avaliacao();
}

void printao(){
	if(contador_avaliados%100 == 0){
		cout << "\t\t"<<contador_avaliados;
		cout << " \t\t"<<contador_criados;
		cout << " \t\t"<<best_avaliacao;
		cout << " \t\t"<<best_limite;
		cout << " \t\t"<<(best_limite-best_avaliacao)/best_avaliacao << "%"<<endl;
	}
}

void bb_recursivo(Mochila m, int i){
	contador_avaliados ++;
	contador_criados--;

	// saida
	printao();

	if (!(m.isViavel())) return; //viabilidade

	avaliacao_g = m.avaliacao();

	//pegando o load atual
	load_g = m.getLoad();

	otimo_rl = RL(m, i, load_g);
	
	// poda por bound
	if (otimo_rl < best_avaliacao) return;

	if(avaliacao_g == otimo_rl){ //Otimalidade

		// checando quem é o melhor
		if (avaliacao_g > best_avaliacao) {
			best_pack = m; //novo melhor
			best_avaliacao = avaliacao_g;
			best_limite = otimo_rl;
			flag = true;
		}
		return;
	}

	if(best_limite > otimo_rl && flag == false) best_limite = otimo_rl;
	
	contador_criados += 2;

	//Chamando filho1
	
	m.x[i] = 1;
	bb_recursivo(m, i+1);	

	 //Chamando filho2
	
	m.x[i] = 0;
	bb_recursivo(m, i+1);
}

void branch_bound(Mochila raiz){
	best_pack = raiz;
	best_avaliacao = best_pack.avaliacao();
	cout << "\t Nohs"<<endl;
	cout << "\tAvaliados \tAbertos \tMelhor Int. \tMelhor Lim. \tGap"<<endl;

	bb_recursivo(raiz, 0);

	cout <<" Numero de Nohs: "<<contador_avaliados<<endl;
}