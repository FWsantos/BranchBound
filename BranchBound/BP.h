#include <vector>
#include <utility>

//Bin Pack
class BP
{
public:
	BP(int capacity_, int n_, std::vector<std::pair<int, int>> items_);
	int capacity; //capacidade da mochila(pack)
	int n; // Quantidade de items
	std::vector<std::pair<int, int>> items;// <pesos, valores>
};

