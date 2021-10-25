#include "pch.h"
#include "Cancion.h"

Cancion::Cancion(string nombre, string artista)
{
	this->nombre = nombre;
	this->artista = artista;
}

string Cancion::getNombre()
{
	return this->nombre;
}

string Cancion::getArtista()
{
	return this->artista;
}
