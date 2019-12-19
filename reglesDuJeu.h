/// \file reglesDuJeu.h
/// \authors Enzo Allemano, Nicolas Viotti, Jonathan Stocchetti
/// \date 18.12.2019
///
/// \brief \b Laboratoire \b 08
/// \brief Créer la fonction coupPossibles et l'enum etatCellule
///
/// Remarque(s) :
///
/// Compilateur :  MinGW-g++ 6.3.0

#ifndef LAB8_REGLESDUJEU_H
#define LAB8_REGLESDUJEU_H

#include <iostream>
#include <vector>

using namespace std;

enum etatCellule {nonExistant, existant, vide};

void coupPossibles(const string& mouvement, vector<vector<etatCellule>>& tablier, int taille, int& compteur, bool& finPartie);

#endif //LAB8_REGLESDUJEU_H
