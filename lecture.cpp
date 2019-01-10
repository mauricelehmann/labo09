#include <iostream>
#include <fstream> // pour ifstream
#include <algorithm>
#include "header/lecture.h"
#include "header/recherche.h"

using namespace std;


vector<string> lecture(const string& fichier){

    vector<string> v;

    ifstream s(fichier);
    string line;

    while (getline(s, line)) {
      v.push_back(line);
    }
    s.close();
    return v;
}

void inverser(vector<string>& dico) {

}

void triABulle(vector<string>& dico){
    bool tableauTrie;
    for(size_t i = dico.size() - 1 ; i > 0 ; i--){
        tableauTrie = true;
        for(size_t j = 0 ; j <= (i - 1) ; j++ ){
            if(estPlusGrand(dico.at(j),dico.at(j+1))){
                swap(dico.at(j+1),dico.at(j));
                tableauTrie = false;
            }
        }
        if(tableauTrie){
            break;
        }
    }
}
