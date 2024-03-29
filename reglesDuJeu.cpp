/// \file reglesDuJeu.cpp
/// \authors Enzo Allemano, Nicolas Viotti, Jonathan Stocchetti
/// \date 18.12.2019
///
/// \brief \b Laboratoire \b 08
/// \brief Contient toutes les fonctions correspondant aux règles du jeu (Mouvement du pion, coups possibles)
///
/// Remarque(s) : 
///
/// Compilateur :  MinGW-g++ 6.3.0

#include <iostream>
#include <vector>

#include "reglesDuJeu.h"

using namespace std;

void mouvementPion(string mouvement, vector<vector<etatCellule>>& tablier, int taille);

/**
 * \name coupPossibles
 * \brief Permet Vérifie les coups possibles et les compare avec l'entrée utilisateur
 * \param mouvement L'entrée utilisateur
 * \param tablier Vecteur avec les valeurs des cellules
 * \param taille Correspond à la taille des lignes/colonnes du tablier
 * \param compteur Permet le décompte des billes jouées
 * \param finPartie Savoir si la partie est terminée
 */
void coupPossibles(const string& mouvement, vector<vector<etatCellule>>& tablier, int taille, int& compteur, bool& finPartie)
{   
    ///Définit la valeur pour compter deux cases de distance
    const int deuxCases=2; 
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
        finPartie = false;
        return;
    }
    
    ///Permet de vérifier la fin du programme après le dernier coup possible
    if(mouvement == "1"){ 
        return;
    }
    
    bool coupPossible=false;
    for (auto & i : coupPossibles) {
       
       ///Gère l'appel d'aide
        if (mouvement == "h") { 
            cout << i << " ";
            coupPossible=true;
        }
        
        //Gère la sortie du programme
        else if(mouvement == "q"){ 
            coupPossible = true;
            finPartie = false;
        }
        
        else if(mouvement == i)
        {
            coupPossible = true;
            mouvementPion(mouvement, tablier, taille);
            compteur--;
            if(compteur == 1){
                if(tablier[3][3]==existant)
                {
                    compteur=0;
                }
            }
        }

    }
    if (!(coupPossible)) {
        cout << "Entrée invalide";
    }

    cout <<endl;

}

/**
* \name mouvementPion
* \brief Gère le déplacement du pion dans la direction voulu et les conséquences
* \param mouvement Le mouvement rentrée par l'utilisateur (32d, 23u..)
* \param tablier Vecteur contenant les données du jeu
* \param taille taille du tablier
*/
void mouvementPion(string mouvement, vector<vector<etatCellule>>& tablier, int taille)
{
    const int zeroAscii=48;
    const int valeurTableauReel = 1;
    const unsigned int coordonneesY = 0;
    const unsigned int coordonneesX = 1;
    const unsigned int direction=2;
    unsigned int valeurY = int(mouvement[coordonneesY]) - zeroAscii - valeurTableauReel; //Récupère les valeurs entières
    unsigned int valeurX = int(mouvement[coordonneesX]) - zeroAscii - valeurTableauReel;
    char directionMouvement = mouvement[direction];

    switch(directionMouvement)
    {///Case sautée
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