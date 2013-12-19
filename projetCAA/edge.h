#ifndef EDGE_H
#define EDGE_H
#include"node.h"

class Edge
{
private:
    Node n1;
    Node n2;
public:
    Edge(Node n1, Node n2);

    friend bool operator== (Edge e1, Edge e2);
    friend bool operator!= (Edge e1, Edge e2);
};

#endif // EDGE_H
