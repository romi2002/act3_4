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

int main() {
    std::ifstream file("bitacora-4_3.txt");

    int n(0), m(0); //Numero de vertices y numero de aristas
    file >> n >> m;

    std::vector<Vertice> vertices;
    std::vector<Arista<Vertice>> aristas;

    for(int i = 0; i < n; i++){
        Vertice v;
        file >> v;
        vertices.push_back(std::move(v));
    }

    for(int i = 0; i < m; i++){
        std::string month, hour, originIp, exitIp, con;
        int day;

        file >> month >> day >> hour;
        file >> originIp >> exitIp;
        getline(file, con);

        originIp = getOnlyIpPart(originIp);
        exitIp = getOnlyIpPart(exitIp);

        Vertice *originV(nullptr), *endV(nullptr);
        for(auto &v : vertices){
            if(v.ip() == originIp) originV = &v;
            else if(v.ip() == exitIp) endV = &v;
        }

        aristas.emplace_back(originV, endV);
    }

    file.close();

    for(const auto &a : aristas){
        auto ipOrigen = a.getvInicio();
        ipOrigen->incrementExitCount();
    }

    std::sort(vertices.begin(), vertices.end(), [](const Vertice &a, const Vertice &b){
        return a.getExitCount() > b.getExitCount();
    });

    //Prints top 10 exits
    for(int i = 0; i < 10; i++){
        std::cout << vertices[i].ip() << " " << vertices[i].getExitCount() << std::endl;
    }

    return 0;
}
