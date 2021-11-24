#pragma once

#include <string>
#include <istream>

class Vertice {
public:
    Vertice(const std::string &ip){
        _ipAddr = ip;
    }

    Vertice() : Vertice("NULLIP") {
        ;
    }

    std::string ip() const{
        return _ipAddr;
    }

private:
    std::string _ipAddr;
};

std::istream& operator>> (std::istream &is, Vertice &v){
    std::string ip;
    is >> ip;
    v = Vertice(ip);
}