/*
 -----------------------------------------------------------------------------------
 Laboratoire : 07
 Fichier     : main.cpp
 Auteur(s)   : Jonathan Stocchetti, Nicolas Viotti, Enzo Allemano
 Date        : 17.12.2019

 But         : Pour ce laboratoire, vous allez mettre en oeuvre le jeu du solitaire dans sa version à 32 billes (tablier anglais).

 Remarque(s) : ('h' pour l'aide et 'q' pour quitter)

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <iostream>
#include "affichage.cpp"
#include "affichage.h"
#include "reglesDuJeu.h"
#include "reglesDuJeu.cpp"

using namespace std;

void initialisationTablier(vector<vector<etatCellule>>& tablier){
    for(int i = 0; i < 7 ; i++){
        for (int j = 0; j < 7; ++j) {
            if(i==2 || i == 3 || i == 4 ){
                tablier[i][j] = existant;
            } else{
                tablier[i][j] = nonExistant;
            }
            tablier[3][3] = vide;
        }
    }
}

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
        coupPossibles("1", tablier, 7, compteurBilles, finPartie);
        if(finPartie){
            string input;
            getline(cin, input);

            coupPossibles(input, tablier, 7, compteurBilles, finPartie);

            affichageTablier(tablier);
        }else{

        }

    } while (finPartie);

    PARFAIT = "Parfait, il ne reste qu'une bille au centre";
    BRAVO = "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait";
    PASMAL= "Pas mal, il ne reste que " + to_string(compteurBilles) + " billes";
    PEUTFAIREMIEUX = "Vous pouvez faire mieux, il reste "+ to_string(compteurBilles) + " billes";

    switch(compteurBilles)
    {
        ///to_string(compteurBilles)
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


