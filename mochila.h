#include <vector>
#include <utility>
#include <cmath>
#include <cfenv>

const int PESO = 0;
const int VALOR = 1;
class Mochila
{
public:
	Mochila();
	Mochila(std::vector<std::vector<double>> peso_valor_, int capacidade_);
  int capacidade;
	std::vector<std::vector<double>> peso_valor; // peso, valor, do item i
	std::vector<double> x;

	bool isViavel();
	double avaliacao();
	double getLoad();
};