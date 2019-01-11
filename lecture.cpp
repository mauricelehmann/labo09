#include "header/lecture.h"
#include "header/utilitaire.h"

using namespace std;

/**
 * Rempli et retourne un vecteur string contenant les éléments d'un fichier
 * Converti également les mots en majuscule pour les futurs comparaisons
 * @param  fichier [description]
 * @return         [description]
 */
vector<string> lecture(const string& fichier){

    vector<string> v;

    ifstream s(fichier);
    string line;

    while (getline(s, line)) {
        //On insert le mot récupéré du fichier, en le normalisant avant, càd le tout en majuscule
        normaliserString(line);
        v.push_back(line);
    }
    s.close();
    return v;
}

void inverser(vector<string>& dico) {
  size_t taille = dico.size();

  for (size_t i = 0, j = taille - 1; i < (taille/2); i++, j--) {
    swap(dico.at(i),dico.at(j));
  }
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

void afficherDico(const std::vector<std::string>& dico){
    for(auto mot : dico){
        cout << mot << endl;
    }
}
