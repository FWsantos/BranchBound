// BranchBound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include "BP.h"
#include "BPSol.h"

int main()
{
	std::vector < std::pair<int, int>> a = { {5, 45}, {8,48}, {3,35} };
	BP mochila(8, 3, a);
	BPSol sol(mochila);
	sol.linearRelaxation();
	std::for_each(sol.sol.begin(), sol.sol.end(), [&](auto item) {
		std::cout << item[2] << "\n";
		});
}
void a() {
#include <iostream>
	// #include <fstream>
	// //#include <sstream>
	// #include <string>
	// #include <vector>
	// #include "BP.h"
	// using namespace std;

	// BP leitura() {
	//     int n = 0; int capacidade = 0; int a = 0;
	//     std::vector<std::pair<int, int>> itens;
	//     vector <int> aux;

	//     ifstream entrada;
	//     entrada.open("entrada.txt");
	//     if (entrada.is_open()) {
	//         entrada >> n;
	//         entrada >> capacidade;

	//         for (int i = 0; i < 2 * n; i++) {
	//                 entrada >> a;
	//                 aux.push_back(a);
	//         }
	//         for (int i = 0; i < n; i++) {
	//             itens.push_back(make_pair(aux[i], aux[i + n]));
	//         }

	//         entrada.close();
	//     }
	//     else {
	//         cout << "erro ao abrir o arquivo!";
	//     }

	//     BP bp(n, capacidade, itens);
	//     return bp;
	// }


	// int main()
	// {
	//     BP bp = leitura();
	//     cout << bp.n  << endl;//teste
	//     cout << bp.capacidade << endl; //teste
	//     for (int i = 0; i < bp.itens.size(); i++) { //teste
	//         cout << bp.itens[i].first << " , " << bp.itens[i].second << endl;
	//     }
	// }
	// itens.push_back(make_pair(aux[i + n], aux[i]));
}