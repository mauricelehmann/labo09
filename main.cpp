//TODO entete etc...

#include <iostream>
#include "header/lecture.h"
#include "header/recherche.h"
using namespace std;

int main(){

    vector<string> v;
    v = lecture("nato");
    std::vector<string> v2;
    v2 = inverser("otan");


    //Pour tester la fonction lecture :
    // for(auto mot : v ){
    //     cout << mot << endl;
    // }

    //Pour tester la fonction inverser :
    // for(auto mot : v2 ){
    //     cout << mot << endl;
    // }

    return EXIT_SUCCESS;
}
