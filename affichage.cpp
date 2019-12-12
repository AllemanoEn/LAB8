#include <iostream>
#include <vector>
#include "reglesDuJeu.h"

using namespace std;

void affichageTablier(vector<vector<etatCellule>> tablier){
    for(int i = 0; i < 7 ; i++){
        for (int j = 0; j < 7; ++j) {
            switch (tablier[i][j]){
                case existant:
                    cout << " " << i << j;
                    break;
                case nonExistant:
                    cout << "   ";
                    break;
                case vide:
                    cout << " ..";
                    break;
            }
        }
        cout << endl;
    }
}

