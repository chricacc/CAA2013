#ifndef GRAPH_H
#define GRAPH_H

#include<string>
#include"listadj.h"
#include<cstdlib>
#include"edge.h"

class Graph
{   
protected:
    int nbVerts;
    int nbEdges;
    std::list<Edge> listEdge;
    std::list<ListAdj> listListAdj;

public:
    Graph();
    Graph(int nbNode, int prob);
    Graph(std::string fileName);

    void addVert(Node node);
    void addEdge(ListAdj *n1, ListAdj *n2);
    std::list<ListAdj> getLists();
    ListAdj* getListFromNode(Node n);
    std::list<Edge> getListEdges();
    int getNbVerts();
    int getNbEdges();
    void display();
    };

#endif // GRAPH_H
