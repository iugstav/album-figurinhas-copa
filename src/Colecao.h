#ifndef COLECAO_H
#define COLECAO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Figurinha.h"

using namespace std;

class Colecao
{
public:
	Colecao(string filePath);
	Colecao(const Colecao &c);
	Colecao();

	void operator=(const Colecao &c);

	void listarFigurinhas();
	int quantidadeDeFigurinhas();
	void colocarFigurinha(Figurinha figurinha);

	void setFilePath(string filePath);
	string getFilePath();

	~Colecao();

private:
	vector<Figurinha> figurinhas;
	string filePath;
	fstream file;

	void handleFileOpening();
	void readDataFromCollection();
};
#endif
