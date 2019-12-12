#include <iostream>
#include "affichage.cpp"
#include "reglesDuJeu.h"
#include "reglesDuJeu.cpp"


using namespace std;

void initialisationTablier(vector<vector<etatCellule>>& tablier){
    for(int i = 0; i < 7 ; i++){
        for (int j = 0; j < 7; ++j) {
            if(i==2 || i == 3 || i == 4 || j==2 || j == 3 || j == 4){
                tablier[i][j] = existant;
            } else{
                tablier[i][j] = nonExistant;
            }
            tablier[3][3] = vide;
        }
    }
}

int main() {

    vector<vector<etatCellule>> tablier(7,vector<etatCellule>(7));
    int compteurBilles=32;
    initialisationTablier(tablier);

    affichageTablier(tablier);
    do {
        string input;
        getline(cin, input);

        coupPossibles(input, tablier, 7, compteurBilles);

        affichageTablier(tablier);
    } while (compteurBilles!=1);

    return 0;
}


