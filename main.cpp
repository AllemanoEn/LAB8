/// \file main.cpp
/// \authors Enzo Allemano, Nicolas Viotti, Jonathan Stocchetti
/// \date 18.12.2019
///
/// \brief \b Laboratoire \b 08
/// \brief Ce programme est le jeu du solitaire dans sa version à 32 billes (tablier anglais).
///
/// Remarque(s) : ('h' pour l'aide et 'q' pour quitter)
///
/// Compilateur :  MinGW-g++ 6.3.0

#include <iostream>
#include "affichage.h"
#include "reglesDuJeu.h"

///includes à supprimer si Netbeans est utilisé
#include "affichage.cpp"
#include "reglesDuJeu.cpp"

using namespace std;

/**
 * \name initialisationTablier
 * \brief Créer le vecteur qui correspond au tablier
 * \param tablier un vecteur qui donne une valeur pour chaque case du tablier
 */
void initialisationTablier(vector<vector<etatCellule>>& tablier){
    for(int i = 0; i < 7 ; i++){
        for (int j = 0; j < 7; ++j) {
            if(i==2 || i == 3 || i == 4 || j == 2 || j == 3 || j == 4 ){
                tablier[i][j] = existant;
            } else{
                tablier[i][j] = nonExistant;
            }
            tablier[3][3] = vide;
        }
    }
}

/**
 * \name main
 * \brief Lance le jeu du solitaire
 * \return 0
 */
int main() {
    int compteurBilles=32;
    bool finPartie = true;
    string PARFAIT;
    string BRAVO;
    string PASMAL;
    string PEUTFAIREMIEUX;

    vector<vector<etatCellule>> tablier(7,vector<etatCellule>(7));
    initialisationTablier(tablier);

    affichageTablier(tablier);
    do {
        //Cette ligne est spéciale, elle recoit "1" en mouvement. Elle ne modifie pas le tablier. Elle sert uniquement à tester si la partie est terminée.
        //Cela évite de devoir re-entrer une valeur pour terminer la partie
        coupPossibles("1", tablier, 7, compteurBilles, finPartie);

        if(finPartie){
            string input;
            getline(cin, input);

            coupPossibles(input, tablier, 7, compteurBilles, finPartie);

            affichageTablier(tablier);
        }

    } while (finPartie);

    PARFAIT = "Parfait, il ne reste qu'une bille au centre";
    BRAVO = "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait";
    PASMAL= "Pas mal, il ne reste que " + to_string(compteurBilles) + " billes";
    PEUTFAIREMIEUX = "Vous pouvez faire mieux, il reste "+ to_string(compteurBilles) + " billes";

    switch(compteurBilles)
    {
        case 0 : cout << PARFAIT;
            break;
        case 1 : cout << BRAVO;
            break;
        case 2 :
        case 3 :
        case 4:
        case 5: cout << PASMAL;
            break;
        default: cout << PEUTFAIREMIEUX;
    }

    return 0;
}


