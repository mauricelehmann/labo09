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
#include "header/recherche.h"
#include "header/lecture.h"
#include "header/utilitaire.h"

using namespace std;

int main(){

    string dicoPath = "dico/";
    string mot;
    vector<string> dictionary,orderedDictionary,inverseDictionary, nato, natoShuffled, otan;

    dictionary          = lecture(dicoPath+"/dictionary.txt");
    orderedDictionary   = lecture(dicoPath+"/ordered_dictionary.txt");
    nato                = lecture(dicoPath+"/nato.txt");
    natoShuffled        = lecture(dicoPath+"/nato_shuffled.txt");
    otan                = lecture(dicoPath+"/otan.txt");

    while(true){

        cout << "Entrez un mot a rechercher dans le dictionnaire : " << endl;
        cin >> mot;
        //On passe le mot en majuscule pour le comparer
        normaliserString(mot);

        cout << "Fonctions de recherches lineaires (dans un dictionnaire non ordre) : " << endl ;
        cout << "Retournant un indice de type size_t : "<< rechercheLineaire(dictionary,mot) << endl;
        cout << "Retournant un iterateur (ici sa position) : "<< distance(dictionary.begin(),rechercheLineaire(dictionary.begin(),dictionary.end(),mot)) << endl;
        cout << endl;
        cout << "Fonctions de recherches dichotomiques (dans un dictionnaire ordre) :" << endl;
        cout << "Retournant un indice de type size_t : " << rechercheDichotomique(orderedDictionary,mot) << endl;

        cout << "Retournant un iterateur (ici sa position): " << distance(orderedDictionary.begin(),rechercheDichotomique(orderedDictionary.begin(),orderedDictionary.end(),mot)) << endl;
        cout << endl;
        cout << "Fonctions de recherches dichotomiques recursives (dans un dictionnaire ordre)" << endl;

        cout << "Retournant vrai si le mot est trouve (avec dictionnaire en parametre) : " << boolalpha << rechercheDichotomiqueRecursive(orderedDictionary,mot,0,-1) << endl;
        cout << "Retournant vrai si le mot est trouve (avec iterateurs en parametre) : " << rechercheDichotomiqueRecursive(orderedDictionary.begin(),orderedDictionary.end()-1,mot) << endl;
        cout << endl;
        cout << "Fonctions de tri a bulles :" << endl ;
        cout << "Fichier 'nato_shuffled.txt' orginial :" << endl ;
        afficherDico(natoShuffled);
        cout << endl;
        cout << "Fichier 'nato_shuffled.txt' apres le tri a bulles :" << endl;
        triABulle(natoShuffled);
        afficherDico(natoShuffled);
        cout << endl << endl;
        cout << "Fonction inverser :" << endl;
        cout << "Fichier 'otan.txt' inverse : (qui doit correspondre exactement a 'nato.txt') : " << endl;
        inverser(otan);
        afficherDico(otan);
        cout << endl;
    }
    return EXIT_SUCCESS;
}
