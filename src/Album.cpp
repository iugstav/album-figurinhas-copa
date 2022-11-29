#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
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
  // setPaginas(1);
  // setFilePath("persistence/album.csv");
}

void Album::operator=(const Album &a)
{
  paginas = a.paginas;
  filePath = a.filePath;
}

int Album::quantidadeDeFigurinhas()
{
  return figurinhas.size();
}

void Album::colarFigurinha(Figurinha figurinha)
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
}

void Album::setFilePath(string newPath)
{
  filePath = newPath;
  handleFileOpening();
  readDataFromAlbum();

  return;
}

void Album::handleFileOpening()
{
  file.open(filePath, fstream::out | fstream::app);
  if (file.fail())
  {
    throw runtime_error("Não foi possível abrir o arquivo");
  }

  return;
}

void Album::readDataFromAlbum()
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

void Album::resetFileState()
{
  file.close();
  handleFileOpening();
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
  file.close();
}