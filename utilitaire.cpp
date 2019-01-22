/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09
 Fichier     : utilitaire.cpp
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 13.01.2019

 But         : Contient les fonctions de comparaison de deux string et de normalisation (tout les char en majuscule)

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "header/utilitaire.h"
using namespace std;


/**
 * Compare deux string donnée selon un ordre alphabetique
 * Si une string est identique mais contient des charactère en plus, elle est considérée plus grande
 * @param  str1 Première string a comparer
 * @param  str2 Deuxième string a comparer
 * @return      Vrai si str1 est plus grande, sinon faux
 */
bool estPlusGrand(const string& str1, const string& str2){
    for( size_t indice = 0 ; indice < str1.size() ; indice++ ){
        //On check que l'indice ne dépasse pas la taille de str2
        if(indice < str2.size()){
            //On compare les deux charactere en les mettant en majuscule
            if((toupper(str1.at(indice))) > (toupper(str2.at(indice)))){
                return true;
            }else if((toupper(str1.at(indice))) < (toupper(str2.at(indice)))){
                return false;
            }
            //Si les deux characteres sont égaux, on continue la comparaison avec les prochains charactere
        }else{
            return true;
        }
    }
    return false ;
}
/**
 * Normalise une string donnée, càd met tout ses charactères en majuscule
 * @param str String à transformer
 */
void normaliserString(string& str){
    transform(str.begin(), str.end(),str.begin(), ::toupper);
}

bool estValide(const char& c){

    if((c >= 97 && c <= 122 ) || c == ' ' ){
        return false;
    }
    return true;
}

void supprimerSymboles(string& ligne){
    ligne.erase(remove_if(ligne.begin(), ligne.end(), estValide), ligne.end());
}
