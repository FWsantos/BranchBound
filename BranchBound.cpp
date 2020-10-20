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

double RL(Mochila crianca, int indice, double load){
	// Mochila.x = vector<crianca.peso_valor.size()>
	vector<double> vpp = std::vector<double>(crianca.peso_valor.size(), 0); //valor por peso
	for (int i = indice; i < crianca.peso_valor.size(); ++i){
		// cout << i << endl;
		vpp[i] = (crianca.peso_valor[i][VALOR]/crianca.peso_valor[i][PESO]);
		// cout << "vpp["<<i+1<<"] = "<<vpp[i]<<endl;
	}

	int maximo;
	for (int i = 0; i < crianca.x.size() - indice; ++i)
	{
		maximo = distance(vpp.begin(), max_element(vpp.begin(), vpp.end()));
		vpp[maximo] = 0;
		// cout << "maximo_i = "<<maximo+1<<endl;

		if(load + crianca.peso_valor[maximo][PESO] <= crianca.capacidade){

			crianca.x[maximo] = 1;
			load = load + crianca.peso_valor[maximo][PESO];
			// cout << "load = "<<load<<endl;

		}else{

			crianca.x[maximo] = (crianca.capacidade - load)/crianca.peso_valor[maximo][PESO];
			// cout << "load = "<<load + crianca.x[maximo]*crianca.peso_valor[maximo][PESO]<<endl;

			return crianca.avaliacao();
		}
	}
	return crianca.avaliacao();
}


void bb_recusivo(Mochila m, int i){
	if (!(m.isViavel())) return; //viabilidade

	avaliacao_g = m.avaliacao();
	// cout << "avaliacao_g " << avaliacao_g << endl;

	//pegando o load atual
	load_g = m.getLoad();
	// cout << "load_g " << load_g << endl;

	otimo_rl = RL(m, i, load_g);
	// cout << "otimo_rl " << otimo_rl << endl;
	
	// poda por bound
	if (otimo_rl < best_avaliacao) return;

	if(avaliacao_g == otimo_rl){ //Otimalidade
		// cout << "otimo " << endl;

		// checando quem é o melhor
		if (avaliacao_g > best_avaliacao) {
			// cout << "best " << endl;
			best_pack = m; //novo melhor
			best_avaliacao = avaliacao_g;
		}
		return;
	} 
	
	//Chamando filho1
	// cout<<"---------------------------------"<<endl;
	// cout<<"filho1"<<endl;
	m.x[i] = 1;
	bb_recusivo(m, i+1);	

	 //Chamando filho2
	// cout<<"---------------------------------"<<endl;
	// cout<<"filho2"<<endl;
	m.x[i] = 0;
	bb_recusivo(m, i+1);
}

void branch_bound(Mochila raiz){
	best_pack = raiz;
	best_avaliacao = best_pack.avaliacao();
	bb_recusivo(raiz, 0);
}