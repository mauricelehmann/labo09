/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09b
 Fichier     : utilitaire.cpp
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 20.01.2019

 But         : Contient les fonctions de suppression des symbole non-alphabetique, de controle de charactère,
               de séparation d'une chaine en mot, de comparaison de deux string
               et de normalisation (tout les char en majuscule).

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "header/utilitaire.h"
using namespace std;

/**
 * Supprime tous symboles non-alphabetique
 * @param ligne Chaine de charactère à modifier
 */
void supprimerSymboles(string& ligne){
    //Tester le char
    char lettre;
    //Pour chaque char de la string
    for(size_t c = 0 ; c < ligne.size() ; c++){
        lettre = ligne.at(c);
        //Si le char n'est pas alphabetique
        if(!estValide(lettre)){
            //On traite les cas spéciaux, tel le guillemet avec "can't" etc...
            if(lettre == '\''){
                //Dans le cas ou le guillemet est au début ou à la fin de la ligne
                if(c == 0 || c == ligne.size() - 1){
                    ligne.erase(c,1);
                    c--;
                //Si le guillemet est entouré de deux lettres, on le laisse
                }else if(!estValide(ligne.at(c-1)) || !estValide(ligne.at(c+1))){
                    ligne.replace(c,1," ");
                }
            }else{
                ligne.replace(c,1," ");
            }
        }
    }
}

/**
 * Test si un charactere est alphabetique ou non.
 * Prend en compte les majuscule et minuscule
 * @param  c charactere à tester
 * @return   True si c'est un charactere alphabetique, sinon false
 */
bool estValide(const char& c){
    //On teste si le charactère n'est pas alphabetique majuscule et minuscule
    if(c < 65 || c > 90){
        if(c < 97 || c > 122){
            return false;
        }
    }
    return true;
}

/**
 * Sépare une chaine de charactere en mot distinct, puis retourne un vecteur<string>
 * les contenant.
 * @param  ligne Ligne à séparer
 * @return       vector<string> contenant chaque mot de la chaine donnée
 */
strVector separerMots(const string& ligne){

    strVector mots;
    string delimiteur = " ";
    size_t dernier = 0;
    size_t suivant = 0;
    //On split la ligne a chaque espaces
    while ((suivant = ligne.find(delimiteur, dernier)) != string::npos) {
        mots.push_back(ligne.substr(dernier, suivant-dernier));
        dernier = suivant + 1;
    }
    return mots;
}

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
    transform(str.begin(), str.end(),str.begin(), ::tolower);
}
