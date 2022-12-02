#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Colecao.h"
#include "Figurinha.h"

using namespace std;

Colecao::Colecao(string filePath)
{
  setFilePath(filePath);
  readDataFromCollection();
}

Colecao::Colecao(const Colecao &c)
{
}

Colecao::Colecao()
{
  // setFilePath("persistence/collection.csv");
}

void Colecao::operator=(const Colecao &c)
{
  filePath = c.filePath;
  setFilePath(filePath);
}

int Colecao::quantidadeDeFigurinhas()
{
  return figurinhas.size();
}

void Colecao::colocarFigurinha(Figurinha figurinha)
{
  if (file.is_open())
  {
    resetFileState();
  }

  file << figurinha.getId() << ","
       << figurinha.getCodigo() << ","
       << figurinha.getTitulo() << ","
       << figurinha.getSecao() << ","
       << figurinha.getTipo()
       << endl;

  figurinhas.push_back(figurinha);
}

void Colecao::retirarFigurinha(vector<string> ids)
{
  int size = this->quantidadeDeFigurinhas();

  for (int i = 0; i < figurinhas.size(); i++)
  {
    for (int j = 0; j < ids.size(); j++)
    {
      if (figurinhas[i].getId() == stoi(ids[j]))
      {
        figurinhas.erase(figurinhas.begin() + i);
      }
    }
  }

  if (figurinhas.size() == size)
  {
    cout << "Id não encontrado na sua coleção" << endl;
  }

  return;
}

void Colecao::writeFromVector()
{
  if (file.is_open())
  {
    resetFileState();
  }
  else
  {
    handleFileOpening();
  }

  for (int i = 0; i < this->figurinhas.size(); i++)
  {
    file << figurinhas[i].getId() << ","
         << figurinhas[i].getCodigo() << ","
         << figurinhas[i].getTitulo() << ","
         << figurinhas[i].getSecao() << ","
         << figurinhas[i].getTipo()
         << endl;
  }
}

void Colecao::listarFigurinhas()
{
  cout << "\n";

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
        << setw(29)
        << figurinhas[i].getTitulo()
        << left
        << setw(12)
        << figurinhas[i].getSecao()
        << left
        << setw(20)
        << figurinhas[i].getTipo()
        << endl;
  }

  cout << "\n";
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

void Colecao::setFigurinhas(vector<Figurinha> v)
{
  this->figurinhas = v;
}

vector<Figurinha> Colecao::getFigurinhas()
{
  return this->figurinhas;
}

void Colecao::handleFileOpening()
{

  file.open(filePath, fstream::out | fstream::app | fstream::in);
  if (file.fail())
  {
    file.open(filePath, fstream::out);
    file.close();

    file.open(filePath, fstream::out | fstream::app | fstream::in);
  }

  return;
}

void Colecao::readDataFromCollection()
{
  vector<vector<string>> conteudo;
  vector<string> linhaDoArquivo;
  string linha, palavra;

  while (getline(file, linha))
  {
    linhaDoArquivo.clear();

    stringstream ss(linha);

    while (getline(ss, palavra, ','))
    {
      linhaDoArquivo.push_back(palavra);
    }
    conteudo.push_back(linhaDoArquivo);
  }

  for (int i = 0; i < conteudo.size(); i++)
  {
    Figurinha tempFig(stoi(conteudo[i][0]),
                      conteudo[i][1],
                      conteudo[i][2],
                      conteudo[i][3],
                      conteudo[i][4]);

    figurinhas.push_back(tempFig);
  }

  return;
}

void Colecao::resetFileState()
{
  file.close();
  handleFileOpening();
}

Colecao::~Colecao()
{
  file.close();
}