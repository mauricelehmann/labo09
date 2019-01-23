/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09
 Fichier     : recherche.h
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 13.01.2019

 But         : Contient les prototype de fonctions de recherche linéaire, dichotomique (recursive et simple)
               Chaque fonction est surchargée afin d'accepter plusieurs type de paramètres tel que :
               f( iterateur de debut du dico , iterateur de fin du dico , mot a rechercher )
               -> retourne un itérateur de vecteur
               ou
               f( dictionnaire, mot a rechercher )
               -> retourne un size_t correspondant à un indexe

               Les fonctions recursive retourne un booléen, vrais pour trouvé, sinon faux

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#ifndef RECHERCHE_H
#define RECHERCHE_H

    #include <string>
    #include <vector>
    #include <ctype.h> //toupper()
    #include <algorithm> //transform()
    #include <iostream>

    #define strVector std::vector<std::string>
    #define strIterator strVector::iterator

    void correcteurOrthographique(const std::vector<strVector>& livre, const strVector& dico);

    /**
     * Recherche une chaine de charactère avec les élément d'une liste donnée
     * Compare la chaine avec les éléments de la liste
     * Complexité en temps : O(n)
     * @param  dico Liste dans laquelle on cherche un mot donné
     * @param  mot  string du mot a chercher
     * @return      Position du mot à chercher dans la liste
     *              Retourne size_t(-1) si le mot n'est pas dans la liste
     */
    size_t rechercheLineaire(const strVector& dico, const std::string& mot);
    /**
     * Recherche une chaine de charactère avec les éléments d'une liste donnée
     * Compare la chaine avec les éléments de la liste
     * Complexité en temps : O(n)
     * @param  itBegin Itérateur vector<string> du premier élément de la liste
     * @param  itEnd   Itérateur vector<string> du dernier élément de la liste
     * @param  mot     string du mot à chercher
     * @return      Iterateur vector<string> du mot à chercher dans la liste
     *              Retourne liste.end() si l'élément n'est pas trouvé
     */
     strIterator rechercheLineaire(strIterator itBegin,strIterator itEnd,const std::string& mot);
     /**
      * Recherche une chaine de charactère dans une liste ordrée
      * Utilise un algorithm de recherche dichotomique :
      * Le premier élément est celui du milieu de la liste
      * Selon sa grandeur par rapport au mot chercher, on redéfinit les bornes de recherches
      * Si il est plus grand, on cherche sur la partie de droite (milieu -> fin)
      * Sinon sur la partie de gauche (Début -> milieu)
      *
      * @param  dico vector<string> Liste dans laquelle on cherche
      * @param  mot  string Mot a rechercher
      * @return positionRetourne size_t  Position du mot à chercher dans la liste
      */
    size_t rechercheDichotomique(const strVector& dico,const std::string& mot);
    /**
     * Recherche une chaine de charactère dans une liste ordrée
     * Utilise un algorithm de recherche dichotomique :
     * Le premier élément est celui du milieu de la liste
     * Selon sa grandeur par rapport au mot chercher, on redéfinit les bornes de recherches
     * Si il est plus grand, on cherche sur la partie de droite (milieu -> fin)
     * Sinon sur la partie de gauche (Début -> milieu)
     *
     * Complexité en temps : O(log n)
     *
     * @param  itDebut Itérateur vector<string> du premier élément de la liste
     * @param  itFin   Itérateur vector<string> du dernier élément de la liste
     * @param  mot  string Mot a rechercher
     * @return itRetourne itérateur du mot à chercher dans la liste
     *         Retourne itFin initial si le mot n'est pas trouvé
     */
    strIterator rechercheDichotomique(strIterator itDebut,strIterator itFin,const std::string& mot);

    /**
     * Recherche une chaine de charactère dans une liste ordrée de manière récursive
     * Utilise un algorithm de recherche dichotomique :
     * Le premier élément est celui du milieu de la liste
     * Selon sa grandeur par rapport au mot chercher, on redéfinit les bornes de recherches
     * Si il est plus grand, on cherche sur la partie de droite (milieu -> fin)
     * Sinon sur la partie de gauche (Début -> milieu)
     *
     * Complexité en temps : O(log n)
     *
     * @param  dico vector<string> Liste dans laquelle on cherche
     * @param  mot  string Mot a rechercher
     * @param debut Correspond à la borne inférieur de recherche
     * @param fin Correspond à la borne supérieur de recherche
     * @return bool Vrai si l'élément est trouvé, sinon faux
     */
    bool rechercheDichotomiqueRecursive(const strVector& dico,const std::string& mot,int debut, int fin);
    /**
     * Recherche une chaine de charactère dans une liste ordrée de manière récursive
     * Utilise un algorithm de recherche dichotomique :
     * Le premier élément est celui du milieu de la liste
     * Selon sa grandeur par rapport au mot chercher, on redéfinit les bornes de recherches
     * Si il est plus grand, on cherche sur la partie de droite (milieu -> fin)
     * Sinon sur la partie de gauche (Début -> milieu)
     *
     *  Complexité en temps : O(log n)
     *
     * @param  mot  string Mot a rechercher
     * @param debut Itérateur vecteur<string> correspond à la borne inférieur de recherche
     * @param fin   Itérateur vecteur<string>Correspond à la borne supérieur de recherche
     * @return bool Vrai si l'élément est trouvé, sinon faux
     */
    bool rechercheDichotomiqueRecursive(strIterator debut,strIterator fin,const std::string& mot);

#endif // RECHERCHE_H
