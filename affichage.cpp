/// \file affichage.cpp
/// \authors Enzo Allemano, Nicolas Viotti, Jonathan Stocchetti
/// \date 18.12.2019
///
/// \brief \b Laboratoire \b 08
/// \brief Contient la fonction pour l'affichage du tablier.
///
/// Remarque(s) : 
///
/// Compilateur :  MinGW-g++ 6.3.0

#include <iostream>
#include <vector>
#include "reglesDuJeu.h"

using namespace std;

/**
 * \name affichageTablier
 * \brief Affiche le tablier à l'aide du vecteur remplie, avec l'état des différentes cellules fait auparavent
 * \param tablier vecteur contenant les valeurs des cellules du tablier
 */
void affichageTablier(vector<vector<etatCellule>> tablier){
    for(int i = 0; i < 7 ; i++){
        for (int j = 0; j < 7; ++j) {
            switch (tablier[i][j]){
                case existant:
                    cout << " " << i+1 << j+1;
                    break;
                case nonExistant:
                    cout << "   ";
                    break;
                case vide:
                    cout << " ..";
                    break;
            }
        }
        cout << endl;
    }
}

