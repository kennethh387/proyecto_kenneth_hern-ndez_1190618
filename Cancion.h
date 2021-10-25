#pragma once
#include <string>

using std::string;
class Cancion
{
	string artista;
	string nombre;

public:
	Cancion(string nombre, string artista);
	string getNombre();
	string getArtista();
};

