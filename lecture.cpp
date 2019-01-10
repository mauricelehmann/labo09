#include <iostream>
#include <fstream> // pour ifstream
#include <algorithm>
#include "header/lecture.h"
#include "header/recherche.h"

using namespace std;


vector<string> lecture(const string& fichier){

    vector<string> v;

    ifstream s("dico/"+fichier+".txt");
    string line;

    while (getline(s, line)) {
      v.push_back(line);
    }
    s.close();
    return v;
}

vector<string> inverser(const string& fichier) {
  vector<string> v;

  ifstream s("dico/"+fichier+".txt");
  string line;

  while(getline(s, line)) {
    v.insert(v.begin(), line);
  }
  s.close();

  return v;
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
/*
tri_à_bulles_optimisé(Tableau T)
    pour i allant de taille de T - 1 à 1
        tableau_trié := vrai
        pour j allant de 0 à i - 1
            si T[j+1] < T[j]
                échanger(T[j+1], T[j])
                tableau_trié := faux
        si tableau_trié
            fin tri_à_bulles_optimisé

 */
