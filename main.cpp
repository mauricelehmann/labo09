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
    vector<string> dictionnaire;

    dictionnaire = lecture(dicoPath+"dictionary.txt");

    return EXIT_SUCCESS;
}
