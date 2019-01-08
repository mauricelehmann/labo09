#include <iostream>
#include <fstream> // pour ifstream
#include "header/lecture.h"

using namespace std;


vector<string> lecture(const string& fichier){

    vector<string> v;

    ifstream s("dico/"+fichier+".txt");
    string line;

    while (getline(s, line)) {
      v.push_back(line);
    }
    s.close();
    return v;
}
