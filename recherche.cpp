/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09
 Fichier     : recherche.cpp
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 13.01.2019

 But         : Contient les fonctions de recherche linéaire, dichotomique (recursive et simple)
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

#include "header/recherche.h"
#include "header/utilitaire.h"
using namespace std;

/**
 * Recherche une chaine de charactère avec les élément d'une liste donnée
 * Compare la chaine avec les élément de la liste
 * Complexité en temps : O(n)
 * @param  dico Liste dans laquelle on cherche
 * @param  mot  string du mot a chercher
 * @return      Position du mot à chercher dans la liste
 *              Retourne size_t(-1) si le mot n'est pas dans la liste
 */
size_t rechercheLineaire(const strVector& dico, const string& mot) {
  size_t indiceMot, fin;
  indiceMot = size_t(-1);
  fin = dico.size();
  //Pour chaque élément du dictionnaire :
  for (size_t i = 0; i < fin; i++) {
    //On compare chaque élément avec le mot recherché
    if(dico.at(i) == mot) {
      return i;
    }
  }

  return indiceMot;
}

/**
 * Recherche une chaine de charactère avec les élément d'une liste donnée
 * Compare la chaine avec les élément de la liste
 * Complexité en temps : O(n)
 * @param  itBegin Itérateur vector<string> du premier élément de la liste
 * @param  itEnd   Itérateur vector<string> du dernier élément de la liste
 * @param  mot     string du mot a chercher
 * @return      Iterateur vector<string> du mot à chercher dans la liste
 *              Retourne liste.end() si l'élément n'est pas trouvé
 */
strIterator rechercheLineaire(strIterator itBegin,strIterator itEnd,const std::string& mot) {

  //Pour chaque élément du dictionnaire :
  for (strIterator i = itBegin; i != itEnd; i++) {
    //On compare chaque élément avec le mot recherché
    if (*i == mot) {
      return i;
    }
  }
  return itEnd;
}

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
 * @param  dico vector<string> Liste dans laquelle on cherche
 * @param  mot  string Mot a rechercher
 * @return positionRetourne size_t  Position du mot à chercher dans la liste
 */
size_t rechercheDichotomique(const strVector& dico,const string& mot){

    size_t debut, milieu, fin, positionRetourne;
    bool trouve = false;
    positionRetourne = dico.size();
    debut = milieu = 0;
    fin = dico.size() - 1;

    do{
        milieu = debut;
        //On définit le nouveau milieu
        milieu = (debut + fin) / 2;
        //Check si l'element du milieu est celui qu'on cherche
        if(dico.at(milieu) == mot){
            trouve = true;
        //Sinon l'element est plus petit, on regarde donc sur la fourchette du debut au milieu
        }else{
            if(estPlusGrand(mot,dico.at(milieu))){
                debut = milieu + 1;
            }else{
                fin = milieu - 1;
            }
        }
    }while(!trouve && debut <= fin);
    //Si le mot a été trouvé
    if(trouve){
        positionRetourne = milieu;
    }
    return positionRetourne;
}

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
strIterator rechercheDichotomique(strIterator itDebut,strIterator itFin,const string& mot){

    //De base, l'iterateur retourné correpondra a dico.end() donc itFin, sauf si on trouve la string recherchée
    strIterator itRetourne = itFin;
    strIterator itMilieu ;
    //dico.end() ne correpond pas au dernier element
    itFin--;
    bool trouve = false;

    do{
        //On initialise l'iterateur du milieu
        itMilieu = itDebut;
        //On définit le nouveau milieu
        //la fonction advance(iterateur, nb d'incrementation) permet d'incrementer un iterateur
        advance(itMilieu,(distance(itDebut,itFin) / 2 )) ;
        //Check si l'element du milieu est celui qu'on cherche
        if(*itMilieu == mot){
            trouve = true;
        //Sinon l'element est plus petit, on regarde donc sur la fourchette du debut au milieu
        }else{
            if(estPlusGrand(mot,*itMilieu)){
                itDebut = itMilieu + 1;
            }else{
                itFin = itMilieu - 1;
            }
        }
    }while(!trouve && itDebut <= itFin);

    if(trouve){
        itRetourne = itMilieu;
    }
    return itRetourne;
}
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
bool rechercheDichotomiqueRecursive(const strVector& dico,const string& mot, int debut = 0 , int fin = -1){

    size_t milieu;

    if(debut == fin){
        if(dico.at(debut) == mot ){
            return true;
        }else{
            return false;
        }
    }
    //Pour la première itération, on définit la borne de fin
    if( fin == -1 ){
        fin = dico.size() - 1;
    }
    //On redéfinit le nouveau milieu
    milieu = (debut+fin) / 2;
    if(dico.at(milieu) == mot ){
        return true;
    }
    //On compare les deux mots et on redéfinit les bornes de recherche
    if(estPlusGrand(dico.at(milieu), mot)){
        return rechercheDichotomiqueRecursive(dico,mot,debut,milieu-1);
    }else{
        return rechercheDichotomiqueRecursive(dico,mot,milieu+1,fin);
    }
}
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
 * @param  mot  string Mot a rechercher
 * @param debut Itérateur vecteur<string> correspond à la borne inférieur de recherche
 * @param fin   Itérateur vecteur<string>Correspond à la borne supérieur de recherche
 * @return bool Vrai si l'élément est trouvé, sinon faux
 */
bool rechercheDichotomiqueRecursive(strIterator debut,strIterator fin,const string& mot){

    strIterator milieu = debut;

    if(debut == fin){
        if(*debut == mot ){
            return true;
        }else{
            return false;
        }
    }
    //On definit le nouveau milieu
    advance(milieu,(distance(debut,fin) / 2 )) ;
    if(*milieu == mot ){
        return true;
    }
    if(estPlusGrand(*milieu, mot)){
        advance(milieu,-1);
        return rechercheDichotomiqueRecursive(debut,milieu,mot);
    }else{
        advance(milieu,1);
        return rechercheDichotomiqueRecursive(milieu,fin,mot);
    }
}
