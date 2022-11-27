#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "Album.h"
#include "Figurinha.h"

using namespace std;

Album::Album(int paginas, string filePath)
{
  setPaginas(paginas);
  setFilePath(filePath);
}

Album::Album(const Album &a)
{
}

Album::Album()
{
  setPaginas(1);
  setFilePath("persistence/album.csv");
}

void Album::operator=(const Album &a)
{
  paginas = a.paginas;
  filePath = a.filePath;
}

void Album::colarFigurinha(Figurinha figurinha)
{
  file << figurinha.getId() << ", "
       << figurinha.getCodigo() << ", "
       << figurinha.getTitulo() << ", "
       << figurinha.getSecao() << ", "
       << figurinha.getTipo() << ", "
       << endl;
}

void Album::listarFigurinhas()
{
  cout
      << left
      << setw(5)
      << "Id"
      << left
      << setw(8)
      << "Codigo"
      << left
      << setw(30)
      << "Título"
      << left
      << setw(14)
      << "Seção"
      << left
      << setw(20)
      << "Tipo"
      << endl;

  for (int i = 0; i < figurinhas.size(); i++)
  {
    cout
        << left
        << setw(5)
        << figurinhas[i].getId()
        << left
        << setw(8)
        << figurinhas[i].getCodigo()
        << left
        << setw(30)
        << figurinhas[i].getTitulo()
        << left
        << setw(14)
        << figurinhas[i].getSecao()
        << left
        << setw(20)
        << figurinhas[i].getTipo()
        << endl;
  }
}

void Album::setFilePath(string newPath)
{
  filePath = newPath;
  handleFileOpening();

  return;
}
void Album::handleFileOpening()
{
  file.open(filePath, ios::out | ios::in);
  if (file.fail())
  {
    cout << "error in album " << filePath << endl;
    throw runtime_error("Não foi possível abrir o arquivo");
  }

  return;
}

void Album::setPaginas(int paginas)
{
  paginas = paginas;
}

string Album::getFilePath()
{
  return filePath;
}

Album::~Album()
{
  this->file.close();
}