//TODO entete etc...
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
    //natoShuffled        = lecture(dicoPath+"/nato_shuffled.txt");
    //otan                = lecture(dicoPath+"/otan.txt");

    while(true){
        cout << "Entrez un mot a rechercher dans le dictionnaire : " << endl;
        cin >> mot;
        //On passe le mot en majuscule pour le comparer
        normaliserString(mot);

        cout << "Fonctions de recherches lineaires (dans un dictionnaire non ordre) : " << endl ;
        cout << "Retournant un indice de type size_t : "<< rechercheLineaire(dictionary,mot) << endl;
        //cout << "Retournant un iterateur : "<< rechercheLineaire(dictionary.begin(),dictionary.end(),mot) << endl;
        cout << endl;
        cout << "Fonctions de recherches dichotomiques (dans un dictionnaire ordre) :" << endl;
        cout << "Retournant un indice de type size_t : " << rechercheDichotomique(orderedDictionary,mot) << endl;
        cout << "Retournant un iterateur (ici sa position): " << distance(orderedDictionary.begin(),rechercheDichotomique(orderedDictionary.begin(),orderedDictionary.end(),mot)) << endl;
        cout << endl;
        cout << "Fonctions de recherches dichotomiques recursives (dans un dictionnaire ordre)" << endl;
        cout << "Retournant un indice de type size_t : " << rechercheDichotomique(orderedDictionary,mot) << endl;
        cout << "Retournant un iterateur (ici sa position): " << distance(orderedDictionary.begin(),rechercheDichotomique(orderedDictionary.begin(),orderedDictionary.end(),mot)) << endl;
        cout << endl;
    }
    return EXIT_SUCCESS;
}
