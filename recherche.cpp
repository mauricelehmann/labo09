#include "header/recherche.h"
#include "header/utilitaire.h"
using namespace std;

size_t rechercheLineaire(const strVector& dico, const string& mot) {
  size_t indiceMot, fin;
  indiceMot = size_t(-1);
  fin = dico.size();

  for (size_t i = 0; i < fin; i++) {
    if(dico.at(i) == mot) {
      return i;
    }
  }

  return indiceMot;
}

strIterator rechercheLineaire(const strIterator& itBegin,const strIterator& itEnd,const string& mot) {
  strIterator i;
  return i;
}

/**
 * [rechercheDichotomique description]
 * @param  dico [description]
 * @param  mot  [description]
 * @return      [description]
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

    if(trouve){
        positionRetourne = milieu;
    }
    return positionRetourne;
}

/**
 * [rechercheDichotomique description]
 * @param  itDebut [description]
 * @param  itFin   [description]
 * @param  mot     [description]
 * @return         [description]
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
 * [rechercheDichotomiqueRecursive description]
 * @param  dico  [description]
 * @param  mot   [description]
 * @param  debut [description]
 * @param  fin   [description]
 * @return       [description]
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
    if( fin == -1 ){
        fin = dico.size() - 1;
    }
    milieu = (debut+fin) / 2;
    if(dico.at(milieu) == mot ){
        return true;
    }
    if(estPlusGrand(dico.at(milieu), mot)){
        return rechercheDichotomiqueRecursive(dico,mot,debut,milieu-1);
    }else{
        return rechercheDichotomiqueRecursive(dico,mot,milieu+1,fin);
    }
}
