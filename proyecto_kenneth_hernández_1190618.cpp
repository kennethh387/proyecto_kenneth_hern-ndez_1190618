#include "pch.h"
#include "lista.h"
#include "Cancion.h"
#include <string>
#include "CompararNombre.h"
#include "cola.h"

using namespace System;
using std::string;

void MarshalString(String^ s, string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

lista<Cancion>* readCanciones(String^ filepath) {
    lista<Cancion>* canciones = new lista<Cancion>();

    array<System::String^>^ lines = System::IO::File::ReadAllLines(filepath);

    for (int i = 0; i < lines->Length; i++)
    {
        array<String^>^ line = lines[i]->Split('-');

        string nombre;
        string artista;
        MarshalString(line[0], nombre);
        MarshalString(line[1], artista);

        Cancion* cancion = new Cancion(nombre, artista);

        canciones->agregar(cancion);
    }
    return canciones;
}

void mostrarCanciones(lista<Cancion>* canciones) {
    Console::WriteLine("Nombre\tArtista\n");

    for (int i = 0; i < canciones->getSize(); i++)
    {
        Cancion* cancion = canciones->Obtener(i);
        String^ nombre = gcnew String(cancion->getNombre().c_str());
        String^ artista = gcnew String(cancion->getArtista().c_str());
        Console::WriteLine("{0}\t{1}",nombre, artista);       
    }
}

int main(array<System::String ^> ^args)
{
    
    Console::WriteLine("Bienvenido a la playlist");
    lista<Cancion>* canciones = readCanciones("Canciones.csv");
    mostrarCanciones(canciones);
    Console::WriteLine("\n Ordenar por Nombre de la;  1)canción    2)artista ");
    String^ opcion1 =  Console::ReadLine();
    if (opcion1->ToLower() == "cancion")
    {
        Console::WriteLine("Ordenar de manera 1)Ascendente    2)Descendente");
        String^ opcion2 = Console::ReadLine();
        if (opcion2->ToLower() == "ascendente")
        {
            canciones = canciones->bubblesort(new CompararNombre());
            mostrarCanciones(canciones);
        }
        else if (opcion2->ToLower() == "descendente")
        {
            canciones = canciones->bubblesorted(new CompararNombre());
            mostrarCanciones(canciones);
        } 
    }
    else if (opcion1->ToLower() == "artista")
    {
        Console::WriteLine("Ordenar de manera 1)Ascendente    2)Descendente");
        String^ opcion2 = Console::ReadLine();
        if (opcion2->ToLower() == "ascendente")
        {
            canciones = canciones->bubblesort(new CompararNombre());
            mostrarCanciones(canciones);
        }
        else if (opcion2->ToLower() == "descendente")
        {
            canciones = canciones->bubblesorted(new CompararNombre());
            mostrarCanciones(canciones);
        }
    }
    while(!canciones->vacio())
    {
        string disponible;
        Console::WriteLine("canciones disponibles;\t" + canciones->getSize());
        Console::WriteLine("\n Desea Reproducir la primera cancion si , no ");
        String^ opcion = Console::ReadLine(); 
        canciones->Obtener(0);
        if (opcion->ToLower() == "si")
        {
            
            canciones->eliminar(0);
            mostrarCanciones(canciones);
            Console::WriteLine("\n");
        }
        else
        {
            mostrarCanciones(canciones);
            Console::WriteLine("\n");
        }    
    }  

    cola<Cancion>* Micola = new cola<Cancion>();
    Console::WriteLine("lista de reproduccion: \n");
    Console::WriteLine("desea agregar una cancion? ");
    String^ nombre = Console::ReadLine();
    Console::WriteLine("ingrese el nombre del artista");
    String^ artista = Console::ReadLine();
    string Artista;
    string Nombre;
    MarshalString(nombre, Nombre);
    MarshalString(artista, Artista);
    Cancion* cancion = new Cancion(Nombre, Artista);
    Micola->Encolar(cancion);
    return 0;

}
