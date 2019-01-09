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

vector<string> inverser(const string& fichier) {
  vector<string> v;

  ifstream s("dico/"+fichier+".txt");
  string line;

  while(getline(s, line)) {
    v.insert(v.begin(), line);
  }
  s.close();

  return v;
}

vector<string> trier(const string& fichier) {
  vector<int> v;

  ifstream s("dico/"+fichier+".txt");
  string line;

  while(getline(s, line)) {
    
  }
  s.close();
  return v;
}
