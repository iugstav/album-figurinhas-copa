#include <iostream>
#include <fstream>
#include <string>

#include "Colecionador.h"
#include "Album.h"
#include "Colecao.h"

using namespace std;

Colecionador::Colecionador(int id, string nome, Album *newAlbum, Colecao *collection)
{
  setId(id);
  setNome(nome);
  setAlbum(*newAlbum);
  setCollection(*collection);
}
Colecionador::Colecionador(Colecionador &c) {}

void Colecionador::mostrarAlbum()
{
  if (album->quantidadeDeFigurinhas() == 0)
  {
    cout << "Seu álbum está vazio. \n"
         << endl;

    return;
  }
  else
  {
    album->listarFigurinhas();

    return;
  }
}

void Colecionador::mostrarColecao()
{
  if (collection->quantidadeDeFigurinhas() == 0)
  {
    cout << "Sua coleção está vazia. \n"
         << endl;

    return;
  }
  else
  {
    collection->listarFigurinhas();

    return;
  }
}

void Colecionador::colarFigurinhaNoAlbum(Figurinha figurinha)
{
  album->colarFigurinha(figurinha);
}

void Colecionador::colocarFigurinhaNaColecao(Figurinha figurinha)
{
  collection->colocarFigurinha(figurinha);
}

void Colecionador::trocarFigurinhas(vector<Figurinha> cedidas, vector<Figurinha> recebidas[]) {}

void Colecionador::setId(int novoId)
{
  id = novoId;
}

void Colecionador::setNome(string novoNome)
{
  name = novoNome;
}

void Colecionador::setAlbum(Album &newAlbum)
{
  album = &newAlbum;
}

void Colecionador::setCollection(Colecao &novaCollection)
{
  collection = &novaCollection;
}

int Colecionador::getId()
{
  return id;
}
