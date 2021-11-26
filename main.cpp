#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "Arista.h"
#include "Vertice.h"

// This function gets only the ip part from a string of ip:port
std::string getOnlyIpPart(const std::string &ipAndPort) {
    size_t portPosition = ipAndPort.find_first_of(':');
    std::string ip = ipAndPort.substr(0, portPosition);
    return ip;
}

//Regresa las ips ordenadas por grado de salida
std::vector<Vertice> getTopIps(const std::map<std::string, Vertice> &m){
    std::vector<Vertice> v;
    v.reserve(m.size());
    //Copiar el mapa de vertices al vector temporal para poder hacer el sort
    for(const auto &vertice : m) {
        v.emplace_back(vertice.second);
    }

    //Realizar un sort con exitCount descendiente
    std::sort(v.begin(), v.end(), [](const Vertice &a, const Vertice &b){
        return a.getExitCount() > b.getExitCount();
    });

    return v;
}

int main() {
    std::ifstream file("bitacora-4_3.txt");

    size_t n(0), m(0); //Numero de vertices y numero de aristas
    file >> n >> m;
    std::map<std::string, Vertice> vertices;
    std::vector<Arista<Vertice>> aristas;

    //Leer todos los vertices del archivo
    for(int i = 0; i < n; i++){
        Vertice v;
        file >> v;
        vertices[v.ip()] = v;
    }

    //Leer los aristas del archivo
    for(int i = 0; i < m; i++){
        //Leer ip de origen y salida, ignorar fecha y el resto de la linea
        std::string month, hour, originIp, exitIp, con;
        int day;

        file >> month >> day >> hour;
        file >> originIp >> exitIp;
        getline(file, con);

        //Obtener solamente el ip, ignorando el puerto
        originIp = getOnlyIpPart(originIp);
        exitIp = getOnlyIpPart(exitIp);

        //Obtener los apuntadores a los vertices de inicio y fin del arista
        auto originV = (Vertice*) &vertices[originIp];
        auto endV = (Vertice*) &vertices[exitIp];

        //Incrementar el numero de entradas y salidas para la ip
        endV->incrementEntryCount();
        originV->incrementExitCount();

        //Agregar al vector de aristas
        aristas.emplace_back(originV, endV);
    }
    file.close();

    //Obtener las ips con el mayor numero de grado de salida
    auto topIps = getTopIps(vertices);

    //Imprimir las top 10 ips
    for(int i = 0; i < 10; i++){
        std::cout << topIps[i].ip() << " " << topIps[i].getExitCount() << std::endl;
    }

    return 0;
}
