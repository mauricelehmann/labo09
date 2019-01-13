/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09
 Fichier     : lecture.cpp
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 13.01.2019

 But         : Contient les fonctions de lecture de fichiers texte, de tri, d'inversion et d'affichage

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "header/lecture.h"
#include "header/utilitaire.h"

using namespace std;

/**
 * Rempli et retourne un vecteur string contenant les éléments d'un fichier
 * Converti également les mots en majuscule pour les futurs comparaisons
 * @param  fichier nom du fichier à lire
 * @return         vecteur string, ou chaque élément correspond à chaque ligne du fichier
 */
vector<string> lecture(const string& fichier){

    vector<string> v;
    //Ouverture du fichier via un flux
    ifstream s(fichier);
    string line;
    //Pour chaque retour à la ligne du fichier...
    while (getline(s, line)) {
        //On insert le mot récupéré du fichier, en le normalisant avant, càd le tout en majuscule
        normaliserString(line);
        //On insert la ligne dans le vecteur
        v.push_back(line);
    }
    s.close();
    return v;
}
/**
 * Inverse l'ordre des éléments d'une liste donnée dans un format vector<string>
 * @param dico Liste à inverser
 */
void inverser(vector<string>& dico) {
  size_t taille = dico.size();
  //Initialise deux itérateur, l'un commençant par la fin, l'autre du début
  for (size_t i = 0, j = taille - 1; i < (taille/2); i++, j--) {
    //On interverti chaque élément "en symétrie"
    swap(dico.at(i),dico.at(j));
  }
}
/**
 * Trie une liste donnée dans un format vector<string>
 * Utilise un algorithm dis "Bubble sort"
 * @param dico Liste à trier
 */
void triABulle(vector<string>& dico){
    bool tableauTrie;
    //On itére dans la liste en commençant par la fin
    for(size_t i = dico.size() - 1 ; i > 0 ; i--){
        tableauTrie = true;
        //Pour chaque éléments entre 0 et (i-1), on compare les éléments par deux en avançant
        for(size_t j = 0 ; j <= (i - 1) ; j++ ){
            if(estPlusGrand(dico.at(j),dico.at(j+1))){
                //Si l'élément de gauche est le plus grand, on interverti les deux éléments
                swap(dico.at(j+1),dico.at(j));
                tableauTrie = false;
            }
        }
        //Si aucun éléments n'a été "swap" durant cette itération, on considère le tableau trié
        if(tableauTrie){
            break;
        }
    }
}
/**
 * Affiche une liste donnée dans un format vector<string>
 * @param dico Liste à afficher
 */
void afficherDico(const std::vector<std::string>& dico){
    for(auto mot : dico){
        cout << mot << endl;
    }
}
