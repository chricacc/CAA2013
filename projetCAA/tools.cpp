#include "tools.h"

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

/*
template<typename T>
bool isInList(T &element, std::list<T> &list)
{
    bool res =false;

    typename std::list<T>::iterator it;
    for (it=list.begin(); it != list.end(); ++it)
        if(element==(*it))
            res = true;

    return res;
}
*/
