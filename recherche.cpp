#include "header/recherche.h"

using namespace std;

strIterator rechercheDichotomique(const strVector& dico,const string& mot);
//Surcharge de la premier fonction -> TODO : Doc doxygen
strIterator rechercheDichotomique(const strIterator& itBegin,const strIterator& itEnd,const string& mot);