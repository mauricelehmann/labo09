/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09b
 Fichier     : main.cpp
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 20.01.2019

 But         : Initialise et rempli les vecteur dictionnaire et texte à corriger
               Appelle la fonction principale correcteurOrthographique(texte,dico)

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "header/recherche.h"
#include "header/lecture.h"
#include "header/utilitaire.h"

using namespace std;

int main(){

    string dicoPath = "files/";
    //On découpe chaque lignes du texte à tester en vecteur contenant chaques mot de la ligne.
    vector<vector<string>> lignesLivre = lectureTexte(dicoPath + "input_sh.txt");
    vector<string> dico = lectureDico(dicoPath + "dictionary.txt");
    //On trie le dictionnaire
    sort(dico.rbegin(),dico.rend(),estPlusGrand);
    //Affiche la liste des mots non-trouvés dans le dictionnaire et le numéro de ligne.
    correcteurOrthographique(lignesLivre,dico);

    return EXIT_SUCCESS;
}
