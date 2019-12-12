#include <iostream>
#include <vector>

using namespace std;

enum etatCellule {nonExistant, existant, vide};


vector<vector<etatCellule>> tablier(8,vector<etatCellule>(8));

void initialisationTablier(){
    for(int i = 1; i < 8 ; i++){
        for (int j = 1; j < 8; ++j) {

            if(i==3 || i == 4 || i == 5 || j==3 || j == 4 || j == 5){
                tablier[i][j] = existant;
            } else{
                tablier[i][j] = nonExistant;
            }
            tablier[4][4] = vide;
        }
    }
}

void affichageTablier(){
    for(int i = 1; i < 8 ; i++){
        for (int j = 1; j < 8; ++j) {
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

