//TODO entete etc...

#include <iostream>

#include "header/recherche.h"
#include "header/lecture.h"
using namespace std;

int main(){

    vector<string> dico;
    dico = lecture("dictionary");


    //Pour tester la fonction lecture :
    for(auto mot : dico ){
        cout << mot << endl;
    }
    cout << endl << endl;

    triABulle(dico);

    //Pour tester la fonction lecture :
    for(auto mot : dico ){
        cout << mot << endl;
    }

    // string val = "Indiar";
    // size_t posRecherchee ;
    // cout << endl << "On cherche : " << val << endl;
    // posRecherchee = rechercheDichotomique(dico,val);
    //
    // if(posRecherchee != dico.size()){
    //     cout << val << " est dans le dico !" << endl ;
    //     cout << "A la position numero " << posRecherchee << endl ;
    // }else{
    //     cout << val << " n est pas dans le dico !" << endl;
    // }
    //
    // //Pour tester rechercheDichotomique() EN MODE ITERATEUR
    // //TODO : Mettre tous ça au propre avec les autre fonctions etc...
    //
    // string val2 = "Indiar";
    // strIterator itVal ;
    // cout << endl << "On cherche : " << val2 << endl;
    //
    // itVal = rechercheDichotomique(dico.begin(),dico.end(),val2);
    // if(itVal != dico.end()){
    //     cout << *itVal << " est dans le dico !" << endl ;
    //     cout << "A la position numero " << distance(dico.begin(),itVal) << endl ;
    // }else{
    //     cout << val2 << " n est pas dans le dico !" << endl;
    // }

    //

    return EXIT_SUCCESS;
}
