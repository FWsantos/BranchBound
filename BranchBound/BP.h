#include <vector>
#include <utility>

//Bin Pack
class BP
{
	BP();
	int capacidade; //capacidade da mochila(pack)
	int n; // Quantidade de itens
	std::vector<std::pair<int, int>> itens;// <pesos, valores>
};

