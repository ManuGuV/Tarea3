//Manuel Guadarrama Villarroel
// https://biblioteca.unirioja.es/tfe_e/TFE001024.pdf
//Complejidad: O(n^2).
//Técnica: Backtracking

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <vector>

bool checaMejorHombre(std::vector<std::vector<int>> pref, int hombre, int mujer, int hombre1, int n);

void asignarParejas(std::vector<std::vector<int>> pref, int columnas);

int main() {
    int columnas = 4;
    
    std::vector<std::vector<int>> pref(2 * columnas, std::vector<int>(columnas));
    
    pref =
    {
        //hombres
        { 4, 5, 6, 7 }, //hombre 0
        { 6, 4, 7, 5 }, //hombre 1
        { 6, 7, 5, 4 }, //hombre 2
        { 5, 7, 6, 4 }, //hombre 3
        
        //mujeres
        { 0, 1, 2, 3 }, //mujer 4
        { 2, 3, 1, 0 }, //mujer 5
        { 1, 2, 0, 1 }, //mujer 6
        { 3, 0, 1, 2 }, //mujer 7
        
    };
    
    asignarParejas(pref, columnas);
    
}


void asignarParejas(std::vector<std::vector<int>> pref, int columnas) {
    
    std::vector<int> parejaMujeres;
    std::vector<bool> asignadosH;

    for (int i = 0; i < columnas; i++) {
        
        parejaMujeres.push_back(-1);
        asignadosH.push_back(false);
        
    }
    
    int solteros = columnas;
    
    while (solteros > 0) {
        
        int hombre;
        
        for (int i = 0; i < columnas; i++) {
            
            if (asignadosH[i] == false) {
                hombre = i;
                i = columnas;
            }
            
        }
        
        for (int i = 0; (i < columnas) && (asignadosH[hombre] == false); i++) {
            
            int mujer = pref[hombre][i];
            
            if (parejaMujeres[mujer - columnas] == -1) {
                parejaMujeres[mujer - columnas] = hombre;
                asignadosH[hombre] = true;
                solteros--;
            }
            
            else {
                
                int otroHombre = parejaMujeres[mujer - columnas];
                
                if (checaMejorHombre(pref, hombre, mujer, otroHombre, columnas) == false) {
                    parejaMujeres[mujer - columnas] = hombre;
                    asignadosH[hombre] = true;
                    asignadosH[otroHombre] = false;
                }
                
            }
            
        }
        
    }
    
    for (int i = 0; i < columnas; i++) {
        std::cout << "La mujer no." << i + columnas << " fue asignada al hombre no." << parejaMujeres[i] << std::endl;
    }
    
}


bool checaMejorHombre(std::vector<std::vector<int>> pref, int hombre, int mujer, int otroHombre, int columnas) {
    
    for (int i = 0; i < columnas; i++) {
        
        if (pref[mujer][i] == otroHombre) {
            return true;
        }
        if (pref[mujer][i] == hombre) {
            return false;
        }
        
    }
    
    return false;
    
}
