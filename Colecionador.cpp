#include <iostream>
#include <fstream>
#include <string>

#include "Colecionador.h"
#include "Album.h"
#include "Colecao.h"

using namespace std;

Colecionador::Colecionador(int id, string nome, Album albumFile, Colecao collectionFile)
{
  setId(id);
  setNome(nome);
  setAlbum(albumFile);
  setCollection(collectionFile);
}

void Colecionador::mostrarAlbum()
{
  return album.listarFigurinhas();
}

void Colecionador::mostrarColecao()
{
  return collection.listarFigurinhas();
}

void Colecionador::colarFigurinhaNoAlbum(Figurinha figurinha)
{
  return album.colarFigurinha(figurinha);
}

void Colecionador::colocarFigurinhaNaColecao(Figurinha figurinha)
{
  return collection.colocarFigurinha(figurinha);
}

void Colecionador::setId(int novoId)
{
  id = novoId;
}

void Colecionador::setNome(string novoNome)
{
  name = novoNome;
}

void Colecionador::setAlbum(Album newAlbum)
{
  album = newAlbum;
}

void Colecionador::setCollection(Colecao novaCollection)
{
  collection = novaCollection;
}

int Colecionador::getId()
{
  return id;
}
