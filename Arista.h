#pragma once

template<typename T>
class Arista {
public:
    Arista(T *origen, T *destino){
        _origen = origen;
        _destino = destino;
    };

    //TODO getters y setters
private:
    T* _origen, *_destino;
};