/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09
 Fichier     : utilitaire.h
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 13.01.2019

 But         : Contient les prototypes des fonctions de comparaison de deux string et de normalisation (tout les char en majuscule)

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef UTILITAIRE_H
#define UTILITAIRE_H

    #include <string>
    #include <algorithm> //transform
    #include <ctype.h> //toupper
    #include <vector>

    //TODO FAIRE LES DEFINE

    void supprimerSymboles(std::string& ligne);

    bool estValide(const char& c);

    std::vector<std::string> separerMots(const std::string& ligne);

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
