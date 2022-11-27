#ifndef FIGURINHA_H
#define FIGURINHA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <assert.h>

using namespace std;

class Figurinha
{
public:
	Figurinha(int novoId, string novoCodigo, string novoTitulo, string novaSecao, string novoTipo);
	Figurinha();
	void trocar(string cedidas[], string recebidas[]);

	void setId(int newId);
	void setCodigo(string newCode);
	void setTitulo(string titulo);
	void setSecao(string newSecao);
	void setTipo(string newTipo);

	int getId();
	string getCodigo();
	string getTitulo();
	string getSecao();
	string getTipo();

private:
	int id;
	string codigo;
	string titulo;
	string secao;
	string tipo;
};
#endif
