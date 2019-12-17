#ifndef LAB8_REGLESDUJEU_H
#define LAB8_REGLESDUJEU_H

#include <iostream>
#include <vector>

using namespace std;

enum etatCellule {nonExistant, existant, vide};

void coupPossibles(const string& mouvement, vector<vector<etatCellule>>& tablier, int taille, int& compteur, bool& finPartie);

#endif //LAB8_REGLESDUJEU_H
