#include <cstdio>
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
  else
  {
    handleFileOpening();
  }

  file << figurinha.getId() << ","
       << figurinha.getCodigo() << ","
       << figurinha.getTitulo() << ","
       << figurinha.getSecao() << ","
       << figurinha.getTipo()
       << endl;

  figurinhas.push_back(figurinha);
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
  readDataFromCollection();

  return;
}

string Colecao::getFilePath()
{
  return filePath;
}

void Colecao::handleFileOpening()
{
  file.open(filePath, fstream::out | fstream::app);
  if (file.fail())
  {
    throw runtime_error("Não foi possível abrir o arquivo");
  }

  return;
}

void Colecao::readDataFromCollection()
{
  vector<vector<string>> conteudo;
  vector<string> linhaDoArquivo;
  string linha, palavra;

  if (file.is_open())
  {
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
  }
  else
  {
    throw runtime_error("could not find file");
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