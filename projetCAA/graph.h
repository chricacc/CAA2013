#ifndef GRAPH_H
#define GRAPH_H

#include<string>
#include"listadj.h"

class Graph
{   
private:
    int nbVerts;
    std::list<ListAdj> listListAdj;

public:
    Graph(int nbNode, int prob);
    Graph(std::string fileName);

    void addVert(Node node);
    void addEdge(ListAdj *n1, ListAdj *n2);
    std::list<ListAdj> getLists();
    ListAdj* getListFromNode(Node n);
    void display();
};

#endif // GRAPH_H
