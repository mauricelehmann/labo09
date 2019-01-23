/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09b
 Fichier     : utilitaire.h
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 20.01.2019

 But         : Contient les prototypes fonctions de suppression des symbole non-alphabetique, de controle de charactère,
               de séparation d'une chaine en mot, de comparaison de deux string
               et de normalisation (tout les char en majuscule).
 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef UTILITAIRE_H
#define UTILITAIRE_H

    #include <string>
    #include <algorithm> //transform
    #include <ctype.h> //toupper
    #include <vector>

    #define strVector std::vector<std::string>

    /**
     * Supprime tous symboles non-alphabetique
     * @param ligne Chaine de charactère à modifier
     */
    void supprimerSymboles(std::string& ligne);
    /**
     * Test si un charactere est alphabetique ou non.
     * Prend en compte les majuscule et minuscule
     * @param  c charactere à tester
     * @return   True si c'est un charactere alphabetique, sinon false
     */
    bool estValide(const char& c);
    /**
     * Sépare une chaine de charactere en mot distinct, puis retourne un vecteur<string>
     * les contenant.
     * @param  ligne Ligne à séparer
     * @return       vector<string> contenant chaque mot de la chaine donnée
     */
    strVector separerMots(const std::string& ligne);
    /**
     * Compare deux string donnée selon un ordre alphabetique
     * Si une string est identique mais contient des charactère en plus, elle est considérée plus grande
     * @param  str1 Première string a comparer
     * @param  str2 Deuxième string a comparer
     * @return      Vrai si str1 est plus grande, sinon faux
     */
    bool estPlusGrand(const std::string& str1, const std::string& str2);
    /**
     * Normalise une string donnée, càd met tout ses charactères en majuscule
     * @param str String a transformer
     */
    void normaliserString(std::string& str);
#endif // UTILITAIRE_H
