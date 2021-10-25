#pragma once
#include "Comparar.h"
#include "Cancion.h"

class CompararNombre :
    public Comparar<Cancion>
{
public: 
    virtual int compare(Cancion a, Cancion b) {
        return a.getNombre().compare( b.getNombre());
    }
        
};

