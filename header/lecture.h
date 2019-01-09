
//TODO entete etc...

#ifndef LECTURE_H
#define LECTURE_H

    #include <string>
    #include <vector>

    /**
     * [permet de lire un dictionnaire]
     * @param fichier [nom du fichier à lire]
     */
    std::vector<std::string> lecture(const std::string& fichier);
    /**
     * [inverse l'ordre des mots d'un dictionnaire]
     * @param fichier [nom du fichier à inverser]
     */
    std::vector<std::string> inverser(const std::string& fichier);
    /**
     * [met les mots d'un dictionnaire pas trié dans l'ordre alphabetique]
     * @param fichier [nom du fichier à trier]
     */
    std::vector<std::string> trier(const std::string& fichier);

#endif // LECTURE_H
