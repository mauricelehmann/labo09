#ifndef UTILITAIRE_H
#define UTILITAIRE_H

    #include <string>
    #include <algorithm> //transform
    #include <ctype.h> //toupper
    /**
     * [estPlusGrand description]
     * @param  str1 [description]
     * @param  str2 [description]
     * @return      [description]
     */
    bool estPlusGrand(const std::string& str1, const std::string& str2);
    void normaliserString(std::string& str);
#endif // UTILITAIRE_H
