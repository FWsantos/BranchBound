#include "mochila.h"

Mochila::Mochila(){}

Mochila::Mochila(std::vector<std::vector<double>> peso_valor_, int capacidade_): capacidade(capacidade_){
	for (int i = 0; i < peso_valor_.size(); ++i)
	{
		peso_valor.push_back(peso_valor_[i]);
		x.push_back(0);
	}
	// peso_valor = std::vector<std::vector<double>>(bp.n, std::vector<double>(2, 0));
}

bool Mochila::isViavel(){
	double soma = 0;
	for (int i = 0; i < peso_valor.size(); ++i){
		soma += x[i]*peso_valor[i][PESO];
		// if(!(x[i] == 1 || x[i] == 0)) return false;
	}
	if(soma <= capacidade) return true;
	return false;
}

double Mochila::avaliacao(){
	double soma = 0;
	for (int i = 0; i < peso_valor.size(); ++i){
		soma += round(x[i]*peso_valor[i][VALOR]);
	}

	return soma;
}

double Mochila::getLoad(){
	double soma = 0;
	for (int i = 0; i < peso_valor.size(); ++i){
		soma += round(x[i]*peso_valor[i][PESO]);
	}

	return soma;	
}
