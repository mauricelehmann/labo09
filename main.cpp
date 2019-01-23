/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09
 Fichier     : main.cpp
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 13.01.2019

 But         : Fichier main, qui montre le bon fonctionnement des 9 fonctions à présenter
               Plusieurs types de dictionnaires sont utilisés selon les fonctions

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

//TODO ESSAYER DE METTRE LES DEFINE ICI

#include "header/recherche.h"
#include "header/lecture.h"
#include "header/utilitaire.h"

using namespace std;

int main(){

    string dicoPath = "files/";
    vector<vector<string>> lignesLivre = lectureTexte(dicoPath + "input_sh.txt");
    vector<string> dico = lectureDico(dicoPath + "dictionary.txt");
    //On trie le dictionnaire
    sort(dico.rbegin(),dico.rend(),estPlusGrand);

    correcteurOrthographique(lignesLivre,dico);

    return EXIT_SUCCESS;
}
