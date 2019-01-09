//TODO entete etc...

#ifndef RECHERCHE_H
#define RECHERCHE_H

    #include <string>
    #include <vector>
    #include <iostream> //A supprimer ?

    #define strVector std::vector<std::string>
    #define strIterator std::vector<std::string>::iterator

    /**
     * [rechercheLineaire description]
     * @param  dico [description]
     * @param  mot  [description]
     * @return      [description]
     */
    strIterator rechercheLineaire(const strVector& dico, const std::string& mot);
    /**
     * [rechercheLineaire description]
     * @param  itBegin [description]
     * @param  itEnd   [description]
     * @param  mot     [description]
     * @return         [description]
     */
    strIterator rechercheLineaire(const strIterator& itBegin,const strIterator& itEnd,const std::string& mot);

    strIterator rechercheDichotomique(const strVector& dico,const std::string& mot);
    //Surcharge de la premier fonction -> TODO : Doc doxygen
    strIterator rechercheDichotomique(strIterator itDebut,strIterator itFin,const std::string& mot);

#endif // RECHERCHE_H
