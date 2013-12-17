#ifndef TREE_H
#define TREE_H

#include<string>
#include<iostream>
#include"listadj.h"

class Tree
{
private:
    int nbVerts;
    std::list<ListAdj> listListAdj;

    bool isCyclicUtil(ListAdj lAdj, bool visited[], ListAdj lAdjParent);

public:
    Tree(int nbNode);
    Tree(std::string fileName);

    void addVert(Node node);
    void addEdge(ListAdj *n1, ListAdj *n2);
    void removeEdge(ListAdj *n1, ListAdj *n2);
    ListAdj* getListFromNode(Node n);

      void display();
};

#endif // TREE_H
