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

    void addNeighbour(Node node);
    void removeNeighbour(Node node);

    void display();
};

//bool isInList(Node node, std::list<Node> list);

#endif // MATADJ_H
