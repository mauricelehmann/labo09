/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09b
 Fichier     : recherche.cpp
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 20.01.2019

 But         : Contient la fonction principal "correcteurOrthographique" retournant tous le mots non-présent
               du dictionnaire dans un texte.
               Contient les fonctions de recherche linéaire, dichotomique (recursive et simple)
               Chaque fonction est surchargée afin d'accepter plusieurs type de paramètres tel que :
               f( iterateur de debut du dico , iterateur de fin du dico , mot a rechercher )
               -> retourne un itérateur de vecteur
               ou
               f( dictionnaire, mot a rechercher )
               -> retourne un size_t correspondant à un indexe

               Les fonctions recursive retourne un booléen, vrais pour trouvé, sinon faux.
               Les mots recherchés ne sont pas sensible à la casse, càd que le mot recherché
               et les mots du dictionnaire sont tous les deux comparés en majuscule uniquement.

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "header/recherche.h"
#include "header/utilitaire.h"

using namespace std;

/**
 * Recherche chaque mot d'un texte donné, dans un dictionnaire donné.
 * Si le mot n'est pas trouvé, on l'affiche ainsi que le numéro de la ligne
 * Si le mot à déjà été detecté comme "non-trouvé" on n'applique pas la recherche dichotomique
 * sur le dictionnaire en entier.
 * @param lignesLivre vecteur de vecteur string, correspondans à chaque ligne et chaque mot du texte à corriger
 * @param dico        vecteur string dictionnaire
 */
void correcteurOrthographique(const vectorStrVector& lignesLivre, const strVector& dico){

    size_t resultat; //Résulat des recherche dichotomique
    size_t tailleDico = dico.size();
    string motNormalise ;
    //Liste des mots non-trouvés dans le dictionnaire
    strVector motsNonTrouves = {};
    //Pour chaque ligne du texte :
    for(size_t ligne = 0 ; ligne < lignesLivre.size() ; ligne ++){
        //Pour chaque mot :
        for(size_t mot = 0 ; mot < lignesLivre.at(ligne).size() ; mot++){
            motNormalise = lignesLivre.at(ligne).at(mot);
            normaliserString(motNormalise);
            //Si le mot n'est pas présent dans la liste des mots "faux",
            //on fait une recherche dichotomique dans le dico
            if(rechercheLineaire(motsNonTrouves,motNormalise) == size_t(-1)){
                resultat = rechercheDichotomique(dico,motNormalise);
                //Si le mot n'est pas trouvé
                if( resultat == tailleDico){
                    motsNonTrouves.push_back(motNormalise);
                    cout << ligne << " : " << lignesLivre.at(ligne).at(mot) << endl;
                }
            }else{
                //Le mot est deja présent dans la liste des mots non-trouvés
                //On l'affiche quand même avec le numéro de ligne
                cout << ligne << " : " << lignesLivre.at(ligne).at(mot) << endl;
            }
        }
    }
}

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
            positionRetourne = milieu;
        //Sinon l'element est plus petit, on regarde donc sur la fourchette du debut au milieu
        }else{
            if(!estPlusGrand(dico.at(milieu),mot)){
                debut = milieu + 1;
            }else{
                fin = milieu - 1;
                if(fin > dico.size()){
                    trouve = true;
                    positionRetourne = fin;
                }
            }
        }
    }while(!trouve && debut <= fin);
    //Si le mot a été trouvé

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
            if(!estPlusGrand(*itMilieu,mot)){
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
        if((unsigned)debut == milieu){
            return false;
        }
        return rechercheDichotomiqueRecursive(dico,mot,debut,milieu-1);
    }else{
        if((unsigned)fin == milieu){
            return false;
        }
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
        //On teste si les bornes sont encore valides
        if(debut == milieu){
            return false;
        }
        //On décremente le milieu de 1
        advance(milieu,-1);
        return rechercheDichotomiqueRecursive(debut,milieu,mot);
    }else{
        //On teste si les bornes sont encore valides
        if(fin == milieu){
            return false;
        }
        //On incrémente le milieu de 1
        advance(milieu,1);
        return rechercheDichotomiqueRecursive(milieu,fin,mot);
    }
}
