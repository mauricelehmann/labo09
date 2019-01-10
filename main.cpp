//TODO entete etc...
#include <iostream> //pour les cout
#include "header/recherche.h"
#include "header/lecture.h"
using namespace std;

int main(){

    vector<string> dico;
    dico = lecture("dico/nato.txt");

    //test inverser
    // for(auto mot : dico) {
    //   cout << mot << endl;
    // }
    //
    // cout << endl << endl;
    //
    // inverser(dico);
    //
    // for(auto mot : dico) {
    //   cout << mot << endl;
    // }

    //test rechercheLineaire
    // size_t test = rechercheLineaire(dico, "Zulur");
    // size_t test2 = rechercheLineaire(dico, "nul");
    // cout << test << endl;
    // cout << test2 << endl;

    return EXIT_SUCCESS;
}
