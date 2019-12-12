//
// Created by jetca on 11.12.2019.
//
#include <iostream>
#include <vector>

using namespace std;
void mouvementPion(string mouvement, int tab[7][7], int taille);

void coupPossibles(int tab[7][7], int taille, string mouvement)
{
    vector<string> coupPossibles;
    for(unsigned i=0; i<taille; i++)
    {
        for (unsigned j=0; j<taille; i++)
        {
            if(tab[i][j]==0)
            {
                if(i+2 <taille && tab[i+2][j]==1 && tab[i+1][j]==1){
                    coupPossibles.push_back(to_string(i)+to_string(j)+'r');
                }
                if (i-2 > 0 < taille && tab[i-2][j] == 1 && tab[i-1][j] == 1)
                {
                    coupPossibles.push_back(to_string(i)+to_string(j)+'l');
                }
                if(j+2 < taille && tab[i][j+2] == 1 && tab[i][j+1] == 1)
                {
                    coupPossibles.push_back(to_string(i)+to_string(j)+'d');
                }
                if(j-2>0 < taille && tab[i][j-2] == 1 && tab[i][j-1] == 1)
                {
                    coupPossibles.push_back(to_string(i)+to_string(j)+'u');
                }
            }
        }

    }
    /*switch(mouvement)
    {

    }*/
    for(auto i = coupPossibles.begin(); i != coupPossibles.end()-1; i++)
    {
        if (*i==mouvement)
        {
            mouvementPion(mouvement, tab,taille);
        }
        else
        {
            ///Coup impossible
        }
    }
}
void coupPossibles()
{

}

void mouvementPion(string mouvement, int tab[7][7], int taille)
{
    const unsigned int coordonneesY = 0;
    const unsigned int coordonneesX = 0;
    const unsigned int direction=2;
    unsigned int valeurY = mouvement[coordonneesY];
    unsigned int valeurX = mouvement[coordonneesX];
    char directionMouvement = mouvement[direction];

    switch(directionMouvement)
    {
        case 'u' : tab[valeurY-1][valeurX] = 0;
            break;
        case 'd' : tab[valeurY+1][valeurX] = 0;
            break;
        case 'l' : tab[valeurY][valeurX-1] = 0;
            break;
        case 'r' : tab[valeurY][valeurX+1] = 0;
            break;
        default : cout << "Entrée invalide" << endl;
    }


}


int reglesDuJeu(int tab[7][7],int taille)
{

    return 0;
}
