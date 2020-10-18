#include "mochila.cpp"
#include <iostream>
// g++ -B mochila.h  main.cpp -o main

int main(int argc, char const *argv[])
{
	Mochila a;
	a.valor = 2;
	std::cout << "Printei karajo "<<a.get() << std::endl;
	return 0;
}