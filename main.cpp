#include "BranchBound.cpp"
#include <fstream>
#include <string>
#include <vector>
// g++ -B mochila.h BranchBound.cpp main.cpp -o main
using namespace std;

Mochila leitura() {
	int n = 0; int capacidade = 0; double a = 0;
	// std::vector<std::pair<int, int>> peso_valor;
	vector <double> aux;
	vector <vector <double>> aux2;

	ifstream entrada;
	entrada.open("entrada.txt");
	if (entrada.is_open()) {
		entrada >> n;
		entrada >> capacidade;

		for (int i = 0; i < 2 * n; i++) {
			entrada >> a;
			aux.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			aux2.push_back({aux[i + n], aux[i]});
			// peso_valor.push_back(make_pair(aux[i], aux[i + n]));
		}

		entrada.close();
	}
	else {
		cout << "erro ao abrir o arquivo!";
	}
	// cout<< capacidade;
	Mochila m = Mochila(aux2, capacidade);
	return m;
}

int main(int argc, char const *argv[])
{
	Mochila a = leitura();
	branch_bound(a);

	cout << "best_avaliacao "<< best_avaliacao<< endl;
	a.x = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	cout << "teste avaliacao "<< a.avaliacao()<< endl; 

	for (int i = 0; i < a.peso_valor.size(); ++i){
		if (a.x[i] != best_pack.x[i])
		{
			cout << "i " << i<<endl;
			// break;
		}
	}
	// cout << "RL " << RL(a, 0, 0) << endl;
	// cout << "RL " << RL(a, 1, 0) << endl;
	// a.x[0] = 1;
	// a.x[2] = 1;
	// cout << "RL " << RL(a, 1, 5) << endl;
	// cout << "RL " << RL(a, 3, 5) << endl;
	return 0;
} 
