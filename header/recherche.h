//TODO entete etc...

#ifndef RECHERCHE_H
#define RECHERCHE_H

    #include <string>
    #include <vector>
    #include <iostream> //A supprimer ?

    #define strVector std::vector<std::string>
    #define strIterator strVector::iterator

    /**
     * [rechercheLineaire description]
     * @param  dico [description]
     * @param  mot  [description]
     * @return      [description]
     */
    size_t rechercheLineaire(const strVector& dico, const std::string& mot);
    /**
     * [rechercheLineaire description]
     * @param  itBegin [description]
     * @param  itEnd   [description]
     * @param  mot     [description]
     * @return         [description]
     */
     strIterator rechercheLineaire(strIterator itBegin,strIterator itEnd,const std::string& mot);
    /**
     * [rechercheDichotomique description]
     * @param  dico [description]
     * @param  mot  [description]
     * @return      [description]
     */
    size_t rechercheDichotomique(const strVector& dico,const std::string& mot);
    /**
     * [rechercheDichotomique description]
     * @param  itDebut [description]
     * @param  itFin   [description]
     * @param  mot     [description]
     * @return         [description]
     */
    strIterator rechercheDichotomique(strIterator itDebut,strIterator itFin,const std::string& mot);

    /**
     * [rechercheDichotomiqueRecursive description]
     * @param  dico  [description]
     * @param  mot   [description]
     * @param  debut [description]
     * @param  fin   [description]
     * @return       [description]
     */
    bool rechercheDichotomiqueRecursive(const strVector& dico,const std::string& mot,int debut, int fin);


#endif // RECHERCHE_H
