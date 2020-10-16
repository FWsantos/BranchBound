#pragma once
#include "BP.h"
#include <iostream>
#include<algorithm> // for copy.
#include<iterator> // for back_inserter

class BPSol {
private:
	double evaluation; //valor da função Objetivo
public:

	BPSol(BP bp);
	std::vector<std::vector<double>> sol; // <pesos, valor, x>
	//bool isResolved();
	void linearRelaxation();
	double updateEvaluation();
	int capacity;
};





