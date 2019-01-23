/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09
 Fichier     : lecture.h
 Auteur(s)   : Gabrielle Thurnherr, Maurice Lehmann
 Date        : 13.01.2019

 But         : Contient prototype des fonctions de lecture de fichiers texte, de tri, d'inversion et d'affichage,
               ainsi que les include des librairies nécessaires.

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#ifndef LECTURE_H
#define LECTURE_H

    #include <string>
    #include <vector>
    #include <fstream> // pour ifstream
    #include <iostream> //pour les cout

    //TODO FAIRE LES DEFINE DES VECTOR

    std::vector<std::vector<std::string>> lectureTexte(const std::string& fichier);

    /**
     * Rempli et retourne un vecteur string contenant les éléments d'un fichier
     * Converti également les mots en majuscule pour les futurs comparaisons
     * @param  fichier nom du fichier à lire
     * @return         vecteur string, ou chaque élément correspond à chaque ligne du fichier
     */
    std::vector<std::string> lectureDico(const std::string& fichier);
    /**
     * Inverse l'ordre des éléments d'une liste donnée dans un format vector<string>
     * @param dico Liste à inverser
     */
    void inverser(std::vector<std::string>& dico);
    /**
     * Trie une liste donnée dans un format vector<string>
     * Utilise un algorithm dis "Bubble sort"
     * @param dico Liste à trier
     */
    void triABulle(std::vector<std::string>& dico);
    /**
     * Affiche une liste donnée dans un format vector<string>
     * @param dico Liste à afficher
     */
    void afficherDico(const std::vector<std::string>& dico);
#endif // LECTURE_H
