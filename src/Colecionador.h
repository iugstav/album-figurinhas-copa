#ifndef COLECIONADOR_H
#define COLECIONADOR_H

#include <string>

#include "Figurinha.h"
#include "Album.h"
#include "Colecao.h"

class Colecionador
{
public:
  Colecionador(int id, string nome, Album *albumFile, Colecao *collectionFile);
  Colecionador(Colecionador &);

  void mostrarAlbum();   // abstração de ListarFigurinhas()
  void mostrarColecao(); // abstração de ListarFigurinhas()
  void colarFigurinhaNoAlbum(Figurinha figurinha);
  void colocarFigurinhaNaColecao(Figurinha figurinha);

  void setId(int id);
  void setNome(string nome);
  void setAlbum(Album &album);
  void setCollection(Colecao &collection);

  int getId();

private:
  int id;
  string name;
  Album *album;
  Colecao *collection;
};
#endif