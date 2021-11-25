#pragma once

template<typename T>

#include "Vertice.h"
class Arista {
public:
    Arista(T *origen, T *destino){
        _origen = origen;
        _destino = destino;
    };
    
  void setvInicio(T *origen){
     _origen = origen;
  }

  void setvFinal(T *destino){
    _destino = destino;
  }

  T* getvInicio(){
    return origen;
  }

  T* getvFinal(){
    return destino;
  }
    //TODO getters y setters
private:
    T *_origen, *_destino;
};
