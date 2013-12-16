#ifndef BIPART_H
#define BIPART_H

#include<string>
#include"listadj.h"

class Bipart
{
private:
    int nbVerts;
    std::list<ListAdj> partLeft;
    std::list<ListAdj> partRight;

public:
    Bipart(int nbNode, int prob);
    void setBipartFromFile(std::string fileName);

    void addVert(Node node);
    void addEdge(ListAdj *n1, ListAdj *n2);

    void display();
};

#endif // BIPART_H
