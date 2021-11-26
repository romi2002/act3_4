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
std::vector<std::pair<std::string, size_t>> getTopIps(const std::map<std::string, std::vector<std::string>> &listaAdj){
    std::vector<std::pair<std::string, size_t>> topIps;
    //Copiar al vector temporal la lista de ips y su grado de coneccion
    for(const auto &v : listaAdj){
        topIps.emplace_back(v.first, v.second.size());
    }

    //Realizar un sort por su grado de coneccion
    std::sort(topIps.begin(), topIps.end(), [](const auto &a, const auto &b){
       return a.second > b.second;
    });

    return topIps;
}

int main() {
    std::ifstream file("bitacora-4_3.txt");

    size_t n(0), m(0); //Numero de vertices y numero de aristas
    file >> n >> m;
    //Guarda el adjacency list representando el grafo,
    //en formato de ip, {vertices adjacentes}
    std::map<std::string, std::vector<std::string>> mapaAdjacencia;

    //Leer todos los vertices del archivo
    for(int i = 0; i < n; i++){
        std::string ip;
        file >> ip;
        mapaAdjacencia[ip] = {};
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

        mapaAdjacencia[originIp].emplace_back(exitIp);
    }
    file.close();

    //Obtener las ips con el mayor numero de grado de salida
    auto topIps = getTopIps(mapaAdjacencia);

    //Imprimir las top 10 ips
    for(int i = 0; i < 10; i++){
        std::cout << topIps[i].first << " " << topIps[i].second << std::endl;
    }

    return 0;
}
