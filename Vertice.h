#pragma once

#include <string>
#include <istream>

class Vertice {
public:
    Vertice(const std::string &ip) {
        _ipAddr = ip;
    }

    Vertice() : Vertice("NULLIP") {
        ;
    }

    std::string ip() const {
        return _ipAddr;
    }

    void incrementEntryCount() {
        entryCount++;
    }

    int getEntryCount() const {
        return entryCount;
    }

    void incrementExitCount() {
        exitCount++;
    }

    int getExitCount() const {
        return exitCount;
    }

private:
    std::string _ipAddr;

    //Grados de salida y de entrada del vertice
    int entryCount = 0;
    int exitCount = 0;
};

/**
 * Funcion utilizada para leer un vertice del archivo
 * @param is
 * @param v
 * @return
 */
std::istream &operator>>(std::istream &is, Vertice &v) {
    std::string ip;
    is >> ip;
    v = Vertice(ip);
    return is;
}