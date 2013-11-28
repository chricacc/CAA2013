#ifndef GRAPH_H
#define GRAPH_H

#include<string>
#include"listadj.h"

class Graph
{   
private:
    int nbVerts;
    std::list<ListAdj> listAdj;

public:
    Graph();
    void setGraphFromFile(std::string fileName);

    void addVert(Node node);
    void addEdge(Node origin, Node dest);

    void Display();
};

#endif // GRAPH_H
