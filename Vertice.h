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

    void incrementExitCount() {
        exitCount++;
    }

    int getExitCount() const {
        return exitCount;
    }

private:
    std::string _ipAddr;
    int exitCount = 0;
};

std::istream& operator>> (std::istream &is, Vertice &v){
    std::string ip;
    is >> ip;
    v = Vertice(ip);
    return is;
}