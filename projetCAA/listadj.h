#ifndef MATADJ_H
#define MATADJ_H

#include<list>
#include "node.h"


class ListAdj
{
private:
    Node node;
    std::list<Node> neighbours;

public:
    ListAdj(Node node);
    ListAdj(Node node, std::list<Node> neighbours);

    Node getNode();
    std::list<Node> getNeighbours();

    void AddEdge(Node node);

    void Display();
};

bool isInList(Node node, std::list<Node> list);

#endif // MATADJ_H
