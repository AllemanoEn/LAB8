//
// Created by jetca on 11.12.2019.
//
#include <iostream>
#include <vector>

using namespace std;
void mouvementPion(string mouvement, vector<vector<etatCellule>> tablier, int taille);

void coupPossibles(string mouvement, vector<vector<etatCellule>> tablier, int taille)
{
    vector<string> coupPossibles;
    for(unsigned i=0; i<taille; i++)
    {
        for (unsigned j=0; j<taille; i++)
        {
            if(tablier[i][j]==vide)
            {
                if(i+2 <taille && tablier[i+2][j]==existant && tablier[i+1][j]==existant){
                    coupPossibles.push_back(to_string(i)+to_string(j)+'r');
                }
                if (i-2 > 0 < taille && tablier[i-2][j] == existant && tablier[i-1][j] == existant)
                {
                    coupPossibles.push_back(to_string(i)+to_string(j)+'l');
                }
                if(j+2 < taille && tablier[i][j+2] == existant && tablier[i][j+1] == existant)
                {
                    coupPossibles.push_back(to_string(i)+to_string(j)+'d');
                }
                if(j-2>0 < taille && tablier[i][j-2] == existant && tablier[i][j-1] == existant)
                {
                    coupPossibles.push_back(to_string(i)+to_string(j)+'u');
                }
            }
        }

    }
    /*switch(mouvement)
    {

    }*/
    if (mouvement != "h") {
        for (auto i = coupPossibles.begin(); i != coupPossibles.end() - 1; i++) {
            if (*i == mouvement) {
                mouvementPion(mouvement, tablier, taille);
            } else {
                cout << "Coup impossible" << endl;
            }
        }
    }
}
void coupPossibles()
{

}

void mouvementPion(string mouvement, vector<vector<etatCellule>> tablier, int taille)
{
    const unsigned int coordonneesY = 0;
    const unsigned int coordonneesX = 1;
    const unsigned int direction=2;
    unsigned int valeurY = mouvement[coordonneesY];
    unsigned int valeurX = mouvement[coordonneesX];
    char directionMouvement = mouvement[direction];

    switch(directionMouvement)
    {
        case 'u' : tablier[valeurY-1][valeurX] = vide;
            break;
        case 'd' : tablier[valeurY+1][valeurX] = vide;
            break;
        case 'l' : tablier[valeurY][valeurX-1] = vide;
            break;
        case 'r' : tablier[valeurY][valeurX+1] = vide;
            break;
        default : cout << "Entrée invalide" << endl;
    }


}
