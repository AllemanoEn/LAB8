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
    int compteurBilles=32;
    bool finPartie = 1;
    const string PARFAIT = "Parfait, il ne reste qu'une bille au centre";
    const string BRAVO = "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait";
    const string PASMAL= "Pas mal, il ne reste que" +to_string(compteurBilles)+ "billes";
    const string PEUTFAIREMIEUX = "Vous pouvez faire mieux, il reste" + to_string(compteurBilles)+ "billes (pour N > 5)";

    vector<vector<etatCellule>> tablier(7,vector<etatCellule>(7));
    initialisationTablier(tablier);

    affichageTablier(tablier);
    do {
        string input;
        getline(cin, input);

        coupPossibles(input, tablier, 7, compteurBilles, finPartie);

        affichageTablier(tablier);
    } while (finPartie);

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
    cout << compteurBilles;

    return 0;
}


