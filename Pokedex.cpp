//
// Created by justi on 10/09/2025.
//

#include <iostream>
#include "Pokedex.h"

void readCSV(const string& nameFile){
    ifstream file(nameFile); //Open file
    if(!file.is_open()){     //File opening verification
        cerr<<"File opening impossible :"<<nameFile<<endl;
        return;
    }

}