//TODO entete etc...

#ifndef RECHERCHE_H
#define RECHERCHE_H

    #include <string>
    #include <vector>
    #include <iostream> //A supprimer ?

    #define strVector std::vector<std::string>
    #define strIterator std::vector<std::string>::iterator

    bool estPlusGrand(const std::string& str1, const std::string& str2);
    size_t rechercheDichotomique(const strVector& dico,const std::string& mot);
    //Surcharge de la premier fonction -> TODO : Doc doxygen
    strIterator rechercheDichotomique(strIterator itDebut,strIterator itFin,const std::string& mot);

#endif // RECHERCHE_H
