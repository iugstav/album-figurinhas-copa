#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <assert.h>

#include "Colecao.h"
#include "Figurinha.h"

using namespace std;

Colecao::Colecao(string filePath)
{
  setFilePath(filePath);
}

Colecao::Colecao(const Colecao &c)
{
}

Colecao::Colecao()
{
  setFilePath("persistence/collection.csv");
}

void Colecao::operator=(const Colecao &c)
{
  filePath = c.filePath;
}

void Colecao::listarFigurinhas()
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

void Colecao::colocarFigurinha(Figurinha figurinha)
{
  file << figurinha.getId() << ", "
       << figurinha.getCodigo() << ", "
       << figurinha.getTitulo() << ", "
       << figurinha.getSecao() << ", "
       << figurinha.getTipo() << ", "
       << endl;
}

void Colecao::setFilePath(string newPath)
{
  filePath = newPath;
  handleFileOpening();
  return;
}

string Colecao::getFilePath()
{
  return filePath;
}

void Colecao::handleFileOpening()
{
  file.open(filePath, ios::out | ios::in);
  if (file.fail())
  {
    cout << "error in collection " << filePath << endl;
    throw runtime_error("Não foi possível abrir o arquivo");
  }

  return;
}

Colecao::~Colecao()
{
  file.close();
}