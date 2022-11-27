#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Figurinha.h"

using namespace std;

class Album
{
public:
	Album(int paginas, string filePath);
	Album(const Album &a);
	Album();

	void operator=(const Album &a);

	void colarFigurinha(Figurinha figurinha);
	void listarFigurinhas();

	void setPaginas(int paginas);
	void setFilePath(string filePath);

	string getFilePath();

	~Album();

private:
	int paginas;
	string filePath;
	fstream file;
	vector<Figurinha> figurinhas;

	void handleFileOpening();
};
#endif
