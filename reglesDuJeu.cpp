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
void coupPossibles(string mouvement, vector<vector<etatCellule>>& tablier, int taille, int& compteur, bool& finPartie)
{   const int deuxCases=2; ///Définit la valeur pour compter deux cases de distance
    const int uneCase=1;
    const int valeurTableauReel=1;
    /// La valeur du tableau à afficher est 44, les index sont à 33, il faut donc ajouter +1 pour avoir la vraie valeur
    vector<string> coupPossibles;
    for(signed i=0; i<taille; i++)
    {
        for (signed j=0; j<taille; j++)
        {
            if(tablier[i][j]==vide)
            {
                if(i+2 <taille && tablier[i+deuxCases][j]==existant && tablier[i+uneCase][j]==existant){
                    coupPossibles.push_back(to_string(i+deuxCases+valeurTableauReel)+to_string(j+valeurTableauReel)+'u');
                }
                if (i-2>=0  && tablier[i-2][j] == existant && tablier[i-1][j] == existant)
                {
                    coupPossibles.push_back(to_string(i-deuxCases+valeurTableauReel)+to_string(j+valeurTableauReel)+'d');
                }
                if(j+2 < taille && tablier[i][j+2] == existant && tablier[i][j+1] == existant)
                {
                    coupPossibles.push_back(to_string(i+valeurTableauReel)+to_string(j+deuxCases+valeurTableauReel)+'l');
                }
                if(j-2>=0  && tablier[i][j-2] == existant && tablier[i][j-1] == existant)
                {
                    coupPossibles.push_back(to_string(i+valeurTableauReel)+to_string(j-deuxCases+valeurTableauReel)+'r');
                }
            }
        }

    }
    if(coupPossibles.empty())
    {
        cout << "Fin de partie"<<endl;
        finPartie = 0;
        return;
    }
    bool coupPossible=0;
    for (auto i = coupPossibles.begin(); i != coupPossibles.end(); i++) {
        if (mouvement == "h") {
            cout << *i << " ";
            coupPossible=true;
        }
        else if(mouvement == *i)
        {
            coupPossible = true;
            mouvementPion(mouvement, tablier, taille);
            compteur--;
        }

    }
        if (!(coupPossible)) {
            cout << "Entrée invalide";

        }

        cout <<endl;

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
    const int zeroAscii=48;
    const int valeurTableauReel = 1;
    const unsigned int coordonneesY = 0;
    const unsigned int coordonneesX = 1;
    const unsigned int direction=2;
    unsigned int valeurY = int(mouvement[coordonneesY]) - zeroAscii - valeurTableauReel;
    unsigned int valeurX = int(mouvement[coordonneesX]) - zeroAscii - valeurTableauReel;
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
            tablier[valeurY][valeurX+2] = existant;
            break;
        default : cout << "Entrée invalide" << endl;
    }


}