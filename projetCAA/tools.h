#ifndef TOOLS_H
#define TOOLS_H

#include<string>
#include<sstream>
#include<vector>
#include<list>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

template <typename T>
bool isInList(T &element, std::list<T> &list)
{
    bool res =false;

    typename std::list<T>::iterator it;
    for (it=list.begin(); it != list.end(); ++it)
        if(element==(*it))
            res = true;

    return res;
}
#endif // TOOLS_H
