
//TODO entete etc...

#ifndef LECTURE_H
#define LECTURE_H

    #include <string>
    #include <vector>

    std::vector<std::string> lecture(const std::string& fichier);
    /**
     * [inverse l'ordre des mots d'un dictionnaire]
     * @param fichier [nom du fichier à inverser]
     */
    std::vector<std::string> inverser(const std::string& fichier);

#endif // LECTURE_H
