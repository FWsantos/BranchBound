
#include "BPSol.h"


BPSol::BPSol(BP bp) {
	capacity = bp.capacity;
	int i = 0;
	//Aloca sol
	sol = std::vector<std::vector<double>>(bp.n, std::vector<double>(3, 0));
	std::for_each(bp.items.begin(), bp.items.end(), [&](auto item) {
		sol[i][0] = item.first;
		sol[i][1] = item.second;
		sol[i][2] = 0;
		i++;
	});	
};

double BPSol::updateEvaluation() {
	evaluation = 0;
	std::for_each(sol.begin(), sol.end(), [&](auto item) {	
		evaluation += item[2] * item[1]; //soma dos valores vezes a quantidade x
	});
	return evaluation; //Resultado avaliado
}

void BPSol::linearRelaxation(){
	std::vector<std::pair<double, int>> mikael;
	int i = 0;
	double a = 0;
	std::for_each(sol.begin(), sol.end(), [&](auto sol_item) {
		a = sol_item[1]*1.0 / sol_item[0];
		mikael.push_back(std::make_pair(a, i));
		i++;
	});

	std::sort(mikael.begin(), mikael.end(), [&](auto m1, auto m2) {
		return 	m1.first > m2.first;
	});

	i = 0;
	int load = 0;
	std::for_each(mikael.begin(), mikael.end(), [&] (auto m_item){
		if (sol[m_item.second][0] + load <= capacity) {
			sol[m_item.second][2] = 1;
			load = load + sol[m_item.second][0];
			std::cout << "load 1 " << load << "\n";
		}
		else if(!(load-capacity == 0)){
			sol[m_item.second][2] = (capacity - load)*1.0 / sol[m_item.second][0];
			load = load + capacity-load;
			std::cout << "load 2 " << load << "\n";
		}
		i++;
	});
}
