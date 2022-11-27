#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Figurinha.h"

Figurinha::Figurinha(int novoId, string novoCodigo, string novoTitulo, string novaSecao, string novoTipo)
{
	setId(novoId);
	setCodigo(novoCodigo);
	setTitulo(novoTitulo);
	setSecao(novaSecao);
	setTipo(novoTipo);
}
Figurinha::Figurinha(){};

void Figurinha::trocar(string cedidas[], string recebidas[])
{
}

void Figurinha::setId(int novoId)
{
	id = novoId;
}

void Figurinha::setCodigo(string novoCodigo)
{
	codigo = novoCodigo;
}

void Figurinha::setTitulo(string novoTitulo)
{
	titulo = novoTitulo;
}

void Figurinha::setSecao(string novaSecao)
{
	secao = novaSecao;
}

void Figurinha::setTipo(string novoTipo)
{
	tipo = novoTipo;
}

int Figurinha::getId()
{
	return id;
}

string Figurinha::getCodigo()
{
	return codigo;
}

string Figurinha::getTitulo()
{
	return titulo;
}

string Figurinha::getSecao()
{
	return secao;
}

string Figurinha::getTipo()
{
	return tipo;
}
