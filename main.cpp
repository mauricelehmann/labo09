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
#include <iostream> //pour les cout & cin
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
    //inverseDictionary   = lecture(dicoPath+"/inverse_dictionary.txt");
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

        /*
            Il semble que les rechercheDichotomique (en tout cas celle recursives) marche avec nato.txt et les petits dico
            Les gros dictionnaire semble être trié de manière pas logique du tout !
            Cela viens du fait des characteres spéciaux tel que le "-" ou "'" qui n'ont pas de place dans l'alphabet
        */

        cout << "Retournant un vrai si le mot est trouve : " << boolalpha << rechercheDichotomiqueRecursive(nato,mot,0,-1) << endl;
        cout << "Retournant un iterateur (ici sa position): " << rechercheDichotomiqueRecursive(nato.begin(),nato.end(),mot) << endl;
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
