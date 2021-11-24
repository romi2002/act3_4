#include <iostream>
#include <fstream>
#include <vector>
#include "Arista.h"
#include "Vertice.h"

int main() {
    std::ifstream file("bitacora-4_3.txt");

    size_t n, m; //Numero de vertices y numero de aristas
    file >> n >> m;

    std::vector<Vertice> vertices;
    std::vector<Arista<Vertice>> aristas;

    for(int i = 0; i < n; i++){
        Vertice v;
        file >> v;
        std::cout << v.ip() << std::endl;
        vertices.push_back(std::move(v));
    }

    //TODO Leer aristas del archivo
    for(int i = 0; i < m; i++){
        ;
    }

    file.close();

    return 0;
}
