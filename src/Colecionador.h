#ifndef COLECIONADOR_H
#define COLECIONADOR_H

#include <string>
#include <vector>

#include "Figurinha.h"
#include "Album.h"
#include "Colecao.h"

class Colecionador
{
public:
  Colecionador(int id, string nome, Album *album, Colecao *collection);
  Colecionador(Colecionador &);

  void mostrarAlbum();   // abstração de ListarFigurinhas()
  void mostrarColecao(); // abstração de ListarFigurinhas()
  void colarFigurinhaNoAlbum(Figurinha figurinha);
  void colocarFigurinhaNaColecao(Figurinha figurinha);
  void trocarFigurinhas(vector<Figurinha> cedidas, vector<Figurinha> recebidas[]);

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