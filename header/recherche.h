//TODO entete etc...

#ifndef RECHERCHE_H
#define RECHERCHE_H

    #include <string>
    #include <vector>

    #define strVector std::vector<std::string>
    #define strIterator std::vector<std::string>::iterator

    strIterator rechercheDichotomique(const strVector& dico,const std::string& mot);
    //Surcharge de la premier fonction -> TODO : Doc doxygen
    strIterator rechercheDichotomique(const strIterator& itBegin,const strIterator& itEnd,const std::string& mot);

#endif // RECHERCHE_H
