#include <iostream>
#include <string>
#include <fstream> // pour ifstream

using namespace std;



int main(){

    ifstream s("dico/dictionary.txt");
    string line;

    while (getline(s, line)) {
      cout << line << endl;
    }
    s.close();


    return 0;
}
