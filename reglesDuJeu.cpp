//
// Created by jetca on 11.12.2019.
//
#include <iostream>
#include <vector>

#include "reglesDuJeu.h"

using namespace std;

void mouvementPion(string mouvement, vector<vector<etatCellule>>& tablier, int taille);
/**
* @name
* @brief
* @param mouvement
* @param tablier
* @param taille
*/
void coupPossibles(string mouvement, vector<vector<etatCellule>>& tablier, int taille)
{
    vector<string> coupPossibles;
    for(unsigned i=1; i<taille; i++)
    {
        for (unsigned j=1; j<taille; j++)
        {
            if(tablier[i][j]==vide)
            {
                if(i+2 <taille && tablier[i+2][j]==existant && tablier[i+1][j]==existant){
                    coupPossibles.push_back(to_string(i+2)+to_string(j)+'u');
                }
                if (i-2 > 0  && tablier[i-2][j] == existant && tablier[i-1][j] == existant)
                {
                    coupPossibles.push_back(to_string(i-2)+to_string(j)+'d');
                }
                if(j+2 < taille && tablier[i][j+2] == existant && tablier[i][j+1] == existant)
                {
                    coupPossibles.push_back(to_string(i)+to_string(j+2)+'l');
                }
                if(j-2>0  && tablier[i][j-2] == existant && tablier[i][j-1] == existant)
                {
                    coupPossibles.push_back(to_string(i)+to_string(j-2)+'r');
                }
            }
        }

    }
    bool coupPossible=0;
    for (auto i = coupPossibles.begin(); i != coupPossibles.end(); i++) {
        if (mouvement == "h") {
            cout << *i << " ";
        }
        else if(mouvement == *i)
        {
            coupPossible = true;
        }
    }
        if (coupPossible) {
            mouvementPion(mouvement, tablier, taille);
            coupPossible = false;
        } else {
            cout << "Entrée invalide";
        }

    cout << endl;
}
/**
* @name mouvementPion
* @brief Gère le déplacement du pion dans la direction voulu et les conséquences
* @param mouvement Le mouvement rentrée par l'utilisateur (32d, 23u..)
* @param tablier Vecteur contenant les données du jeu
* @param taille taille du tablier
*/
void mouvementPion(string mouvement, vector<vector<etatCellule>>& tablier, int taille)
{
    const unsigned int coordonneesY = 0;
    const unsigned int coordonneesX = 1;
    const unsigned int direction=2;
    unsigned int valeurY = int(mouvement[coordonneesY]) - 48;
    unsigned int valeurX = int(mouvement[coordonneesX]) - 48;
    char directionMouvement = mouvement[direction];

    switch(directionMouvement)
    {
        case 'u' :  tablier[valeurY-1][valeurX] = vide; ///Case sautée
            tablier[valeurY][valeurX]=vide; ///Case actuelle
            tablier[valeurY-2][valeurX] = existant; ///Prochaine case
            break;
        case 'd' :  tablier[valeurY+1][valeurX] = vide;
            tablier[valeurY][valeurX]=vide;
            tablier[valeurY+2][valeurX] = existant;
            break;
        case 'l' :  tablier[valeurY][valeurX-1] = vide;
            tablier[valeurY][valeurX]=vide;
            tablier[valeurY][valeurX-2] = existant;
            break;
        case 'r' :  tablier[valeurY][valeurX+1] = vide;
            tablier[valeurY][valeurX]=vide;
            tablier[valeurY][valeurX+2] = vide;
            break;
        default : cout << "Entrée invalide" << endl;
    }


}