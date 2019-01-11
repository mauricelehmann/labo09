
//TODO entete etc...

#ifndef LECTURE_H
#define LECTURE_H

    #include <string>
    #include <vector>
    #include <fstream> // pour ifstream
    #include <iostream>
    //#include <algorithm> //Pour swap()

    /**
     * [permet de lire un dictionnaire]
     * @param fichier [nom du fichier à lire]
     */
    std::vector<std::string> lecture(const std::string& fichier);
    /**
     * [inverse l'ordre des mots d'un dictionnaire]
     * @param fichier [nom du fichier à inverser]
     */
    void inverser(std::vector<std::string>& dico);
    /**
     * [triABulle trie les string d'un vecteur et les mets dans l'ordre alphabétique]
     * @param dico [vecteur à trier]
     */
    void triABulle(std::vector<std::string>& dico);
    /**
     * [afficherDico description]
     * @param dico [description]
     */
    void afficherDico(const std::vector<std::string>& dico);
#endif // LECTURE_H
