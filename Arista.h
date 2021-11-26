#pragma once
#include "Vertice.h"

template<typename T>
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

  T* getvInicio() const {
    return _origen;
  }

  T* getvFinal() const {
    return _destino;
  }
    //TODO getters y setters
private:
    T *_origen, *_destino;
};
