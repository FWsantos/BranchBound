#include "BranchBound.cpp"
#include <fstream>
#include <string>
#include <vector>
//  g++ -B mochila.h main.cpp -o main
using namespace std;

Mochila leitura() {
	int n = 0; int capacidade = 0; double a = 0;
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
		}

		entrada.close();
	}
	else {
		cout << "erro ao abrir o arquivo!";
	}
	Mochila m = Mochila(aux2, capacidade);
	return m;
}

int main(int argc, char const *argv[])
{
	Mochila a = leitura();
	branch_bound(a);

	return 0;
} 
